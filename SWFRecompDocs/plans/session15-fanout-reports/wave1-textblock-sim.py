#!/usr/bin/env python3
"""w1-textblock: simulator of the Ruffle FTE line-lifecycle model.

Purpose: prove (or refute) that the mechanism set
  (A) lastLine = tail of first_line->next_line chain
  (B) TextLine::release() + releaseLines() reachability algorithm + #2004/#2007
  (C) hide_block_from_script for validity="static"
is COMPLETE for avm2/textblock_line_changes and avm2/textblock_releaselines,
by reproducing their output.ruffle.txt byte-for-byte.
"""
import sys

out = []
def trace(s): out.append(str(s))


class Err(Exception):
    def __init__(self, kind, msg, frame):
        self.txt = "%s: %s\n\tat %s()\n\tat Test()" % (kind, msg, frame)


def e2004(frame):
    return Err("ArgumentError", "Error #2004: One of the parameters is invalid.", frame)


def e2007(param, frame):
    return Err("TypeError", "Error #2007: Parameter %s must be non-null." % param, frame)


class Line:
    def __init__(self):
        self.reset()
    def reset(self):
        self.validity = "valid"
        self.block = None        # internal link
        self.hide = False        # hide_block_from_script
        self.specified_width = 0.0
        self.raw = 0
        self.begin = 0
        self.end = 0
        self.line_index = 0
        self.prev = None
        self.next = None
    # script-visible
    @property
    def script_block(self):
        return None if self.hide else self.block
    def set_validity(self, v):
        if v == "static":
            self.hide = True
        self.validity = v
    def next_lines(self):
        l = self.next
        while l is not None:
            yield l
            l = l.next
    def release(self):
        block = self.block
        assert block is not None
        bfirst = block.first_line
        prev, nxt = self.prev, self.next
        if self is bfirst:
            block.first_line = nxt
        self.set_validity("invalid")
        for l in list(self.next_lines()):
            l.set_validity("invalid")
        if prev is not None:
            prev.next = nxt
        if nxt is not None:
            nxt.prev = prev
        self.block = None
        self.prev = None
        self.next = None


def next_line_break(text, start):
    i = start
    while i < len(text):
        c = text[i]
        if c in ("\n", "\r", " ", " "):
            if c == "\r" and i + 1 < len(text) and text[i + 1] == "\n":
                return i + 2
            return i + 1
        i += 1
    return len(text)


class Block:
    def __init__(self, text=None):
        self.text = text
        self.first_line = None
        self.creation_result = None
    def lines(self):
        l = self.first_line
        while l is not None:
            yield l
            l = l.next
    @property
    def last_line(self):
        last = None
        for l in self.lines():
            last = l
        return last
    def set_content(self, text):
        for l in self.lines():
            l.set_validity("invalid")
        self.text = text

    def _do_create(self, line_to_use, prev, width):
        text = self.text
        pos = prev.end if prev is not None else 0
        if pos > len(text):
            self.creation_result = "complete"
            return None
        nxt = next_line_break(text, pos)
        if len(text) == 0 or (nxt == len(text) and pos == nxt):
            self.creation_result = "complete"
            return None
        li = prev.line_index + 1 if prev is not None else 0
        if line_to_use is not None:
            line_to_use.reset()
            line = line_to_use
        else:
            line = Line()
        line.block = self
        line.specified_width = width
        line.raw = nxt - pos
        line.begin = pos
        line.end = nxt
        line.line_index = li
        if prev is not None:
            line.prev = prev
            prev.next = line
        else:
            self.first_line = line
        self.creation_result = "success"
        return line

    def createTextLine(self, prev=None, width=1000000.0):
        if self.text is None:
            return None
        if prev is not None:
            if prev.validity != "valid" or prev.script_block is not self:
                raise e2004("flash.text.engine::TextBlock/createTextLine")
        if width < 0 or width > 1000000:
            raise e2004("flash.text.engine::TextBlock/createTextLine")
        return self._do_create(None, prev, width)

    def recreateTextLine(self, tl, prev=None, width=1000000.0):
        if tl is None:
            raise e2004("flash.text.engine::TextBlock/recreateTextLine")
        if prev is not None:
            if prev.validity != "valid" or prev.script_block is not self or prev is tl:
                raise e2004("flash.text.engine::TextBlock/recreateTextLine")
        if width < 0 or width > 1000000:
            raise e2004("flash.text.engine::TextBlock/recreateTextLine")
        return self._do_create(tl, prev, width)

    def releaseLines(self, a, b):
        F = "flash.text.engine::TextBlock/releaseLines"
        if a is None:
            raise e2007("firstLine", F)
        if b is None:
            raise e2007("lastLine", F)
        match = lambda l: l is a or l is b
        seq = list(self.lines())
        first_position = None
        for i, l in enumerate(seq):
            if match(l):
                first_position = i
                break
        if first_position is None:
            raise e2004(F)
        if a is b:
            a.release()
            return
        cnt = None
        for j, l in enumerate(seq[first_position + 1:]):
            if match(l):
                cnt = j + 2
                break
        if cnt is None:
            raise e2004(F)
        for line in seq[first_position:first_position + cnt]:
            line.release()


# ---------------------------------------------------------------- harness
def fmt(line, lst):
    if line is None:
        return "null"
    try:
        return "line-%d" % lst.index(line)
    except ValueError:
        return "line-unknown"


def dumpInfo(block, lst):
    trace("First line in block: " + fmt(block.first_line, lst))
    trace("Last line in block: " + fmt(block.last_line, lst))
    for i, line in enumerate(lst):
        trace("Line #%d:" % i)
        trace("    line.validity: " + line.validity)
        trace("    line.textBlock: " + ("null" if line.script_block is None
                                        else "[object TextBlock]"))
        trace("    line.previousLine: " + fmt(line.prev, lst))
        trace("    line.nextLine: " + fmt(line.next, lst))


def attempt(fn):
    try:
        fn()
    except Err as e:
        trace(e.txt)


TEXT = ("Lorem ipsum dolor\nsit amet, consectetur adipiscing elit, sed\n"
        "do eiusmod tempor\nincididunt ut labore\net dolore magna\n"
        "aliqua. Ut enim ad")


def test_line_changes():
    block = Block(TEXT)
    l0 = block.createTextLine(None, 1000)
    l1 = block.createTextLine(l0, 1000)
    l2 = block.createTextLine(l1, 1000)
    l3 = block.createTextLine(l2, 1000)
    l4 = block.createTextLine(l3, 1000)
    lst = [l0, l1, l2, l3, l4]
    dumpInfo(block, lst)
    l2.set_validity("invalid")
    dumpInfo(block, lst)
    l2.set_validity("static")
    dumpInfo(block, lst)
    r = block.recreateTextLine(l1, l0, 1000)
    trace("Calling recreateTextLine returns the same line: " + ("true" if r is l1 else "false"))
    dumpInfo(block, lst)
    trace("Calling releaseLines(line1, line2)")
    attempt(lambda: block.releaseLines(l1, l2))
    trace("Calling releaseLines(line2, line3)")
    attempt(lambda: block.releaseLines(l2, l3))
    l3.set_validity("static")
    dumpInfo(block, lst)
    cr = block.createTextLine(None, 1000)
    trace("Calling createTextLine returns the same line: " + ("true" if l0 is cr else "false"))
    dumpInfo(block, lst)
    l4.set_validity("static")
    dumpInfo(block, lst)
    def reset5():
        block.recreateTextLine(l0, None, 1000)
        block.recreateTextLine(l1, l0, 1000)
        block.recreateTextLine(l2, l1, 1000)
        block.recreateTextLine(l3, l2, 1000)
        block.recreateTextLine(l4, l3, 1000)
    reset5()
    dumpInfo(block, lst)
    trace("Take two!")
    block.recreateTextLine(l1, l0, 1000)
    dumpInfo(block, lst)
    trace("Calling releaseLines(line1, line2)")
    attempt(lambda: block.releaseLines(l1, l2))
    trace("Calling releaseLines(line2, line3)")
    attempt(lambda: block.releaseLines(l2, l3))
    reset5()
    dumpInfo(block, lst)
    l5 = block.createTextLine(l4, 1000)
    lst.append(l5)
    dumpInfo(block, lst)
    block.createTextLine(l4, 1000)
    dumpInfo(block, lst)
    def reset6():
        block.recreateTextLine(l0, None, 1000)
        block.recreateTextLine(l1, l0, 1000)
        block.recreateTextLine(l2, l1, 1000)
        block.recreateTextLine(l3, l2, 1000)
        block.recreateTextLine(l4, l3, 1000)
        block.recreateTextLine(l5, l4, 1000)
    reset6()
    block.releaseLines(l2, l4)
    dumpInfo(block, lst)
    block.releaseLines(l5, l5)
    dumpInfo(block, lst)
    reset6()
    block.set_content(block.text)   # content = content
    dumpInfo(block, lst)
    reset6()
    block.set_content("some text here")
    dumpInfo(block, lst)


def test_releaselines():
    block = Block(TEXT)
    l0 = block.createTextLine(None, 1000)
    l1 = block.createTextLine(l0, 1000)
    l2 = block.createTextLine(l1, 1000)
    l3 = block.createTextLine(l2, 1000)
    l4 = block.createTextLine(l3, 1000)
    l5 = block.createTextLine(l4, 1000)
    lst = [l0, l1, l2, l3, l4, l5]
    trace("!!!! initialized list of six lines, line0..=line5")
    dumpInfo(block, lst)
    trace('!! block.releaseLines(null, null);')
    attempt(lambda: block.releaseLines(None, None))
    trace('!! block.releaseLines(null, line4);')
    attempt(lambda: block.releaseLines(None, l4))
    trace('!! block.releaseLines(line1, null);')
    attempt(lambda: block.releaseLines(l1, None))
    trace('!! line1.validity = "static";')
    l1.set_validity("static")
    trace('!! block.releaseLines(line1, line2);')
    attempt(lambda: block.releaseLines(l1, l2))
    dumpInfo(block, lst)
    trace('!! line3.validity = "invalid";')
    l3.set_validity("invalid")
    trace('!! block.releaseLines(line3, line4);')
    attempt(lambda: block.releaseLines(l3, l4))
    dumpInfo(block, lst)

    def reset6():
        block.recreateTextLine(l0, None, 1000)
        block.recreateTextLine(l1, l0, 1000)
        block.recreateTextLine(l2, l1, 1000)
        block.recreateTextLine(l3, l2, 1000)
        block.recreateTextLine(l4, l3, 1000)
        block.recreateTextLine(l5, l4, 1000)
    reset6()
    trace("!!!! reset all lines")
    trace('!! block.createTextLine(line4, 1000);')
    block.createTextLine(l4, 1000)
    dumpInfo(block, lst)
    trace('!! block.releaseLines(line3, line5);')
    attempt(lambda: block.releaseLines(l3, l5))
    trace('!! block.releaseLines(null, line5);')
    attempt(lambda: block.releaseLines(None, l5))
    trace('!! block.releaseLines(line5, null);')
    attempt(lambda: block.releaseLines(l5, None))
    dumpInfo(block, lst)
    reset6()
    trace("!!!! reset all lines")
    trace('!! block.releaseLines(line5, line4);')
    attempt(lambda: block.releaseLines(l5, l4))
    dumpInfo(block, lst)
    trace('!! block.releaseLines(line3, line1);')
    attempt(lambda: block.releaseLines(l3, l1))
    reset6()
    trace("!!!! reset all lines")
    dumpInfo(block, lst)
    trace('!! block.releaseLines(line2, line5);')
    block.releaseLines(l2, l5)
    dumpInfo(block, lst)
    trace('!! block.releaseLines(line1, line3);')
    attempt(lambda: block.releaseLines(l1, l3))
    trace('!! block.releaseLines(line2, line3);')
    attempt(lambda: block.releaseLines(l2, l3))
    trace('!! block.releaseLines(line4, line0);')
    attempt(lambda: block.releaseLines(l4, l0))
    trace('!! block.releaseLines(line0, line1);')
    block.releaseLines(l0, l1)
    dumpInfo(block, lst)
    trace('!! block.releaseLines(line1, line3);')
    attempt(lambda: block.releaseLines(l1, l3))
    dumpInfo(block, lst)
    reset6()
    trace("!!!! reset all lines")
    trace('!! block.releaseLines(line4, line4);')
    block.releaseLines(l4, l4)
    dumpInfo(block, lst)
    trace('!! block.releaseLines(line4, line5);')
    attempt(lambda: block.releaseLines(l4, l5))
    trace('!! block.releaseLines(line3, line4);')
    attempt(lambda: block.releaseLines(l3, l4))
    trace('!! block.releaseLines(line4, line3);')
    attempt(lambda: block.releaseLines(l4, l3))
    trace('!! block.releaseLines(line3, line5);')
    block.releaseLines(l3, l5)
    dumpInfo(block, lst)
    reset6()
    trace("!!!! reset all lines")
    trace('!! line1.validity = "static";')
    l1.set_validity("static")
    trace('!! line2.validity = "static";')
    l2.set_validity("static")
    dumpInfo(block, lst)
    trace('!! block.releaseLines(line1, line2);')
    block.releaseLines(l1, l2)
    dumpInfo(block, lst)
    trace('!! block.releaseLines(line0, line4);')
    block.releaseLines(l0, l4)
    dumpInfo(block, lst)
    reset6()
    trace("!!!! reset all lines")
    block2 = Block("Oremlay ipsumyay olorday\nitsay ametway, onsecteturcay "
                   "adipiscingyay elitway, edsay")
    trace("!!!! Created a completely different text block, block2")
    trace('!! block2.releaseLines(line1, line4);')
    attempt(lambda: block2.releaseLines(l1, l4))
    dumpInfo(block, lst)
    reset6()
    trace("!!!! reset all lines")
    trace('!! line4.validity = "static";')
    l4.set_validity("static")
    trace('!! line5.validity = "static";')
    l5.set_validity("static")
    dumpInfo(block, lst)
    trace('!! block.releaseLines(line2, line4);')
    block.releaseLines(l2, l4)
    dumpInfo(block, lst)
    b2l = block2.createTextLine(None, 1000)
    lst.append(b2l)
    trace('!!! Created a line from block2, "block2Line" aka "line6"')
    dumpInfo(block, lst)
    trace('!! block.releaseLines(block2Line, null);')
    attempt(lambda: block.releaseLines(b2l, None))
    trace('!! block.releaseLines(null, block2Line);')
    attempt(lambda: block.releaseLines(None, b2l))
    trace('!! block.releaseLines(block2Line, block2Line);')
    attempt(lambda: block.releaseLines(b2l, b2l))
    trace('!! block.releaseLines(block2Line, line0);')
    attempt(lambda: block.releaseLines(b2l, l0))
    trace('!! block.releaseLines(line1, block2Line);')
    attempt(lambda: block.releaseLines(l1, b2l))
    lst.pop()
    reset6()
    trace("!!!! reset all lines")
    trace('!! line0.validity = "static";')
    l0.set_validity("static")
    trace('!! block.releaseLines(line0, line1);')
    block.releaseLines(l0, l1)
    dumpInfo(block, lst)


def test_raw_text_length():
    def dump(text):
        block = Block(text)
        line = block.createTextLine(None, 10000)
        idx = 0
        while line:
            trace("  line %d: rawTextLength=%d textBlockBeginIndex=%d first=%s"
                  % (idx, line.raw, line.begin,
                     "true" if block.first_line is line else "false"))
            line = block.createTextLine(line, 10000)
            idx += 1
    for label, txt in [("One line per line break", "ab\ncd"),
                       ("Carriage Return", "ab\rcd"),
                       ("Carriage Return + Line Feed", "ab\r\ncd"),
                       ("Double Line Feed", "ab\n\ncd"),
                       ("Line separator", "ab cd"),
                       ("Paragraph separator", "ab cd"),
                       ("No line break", "abcd"),
                       ("Trailing line break", "ab\n")]:
        trace(label)
        dump(txt)
        if label != "Trailing line break":
            trace("")


if __name__ == "__main__":
    which = sys.argv[1]
    {"lc": test_line_changes, "rl": test_releaselines,
     "rt": test_raw_text_length}[which]()
    print("\n".join(out))
