# XML/XMLNode Implementation Plan
<!-- TESTS: xml, xml_append_child, xml_append_child_with_parent, xml_attributes_read, xml_cdata, xml_child_nodes_edge_cases, xml_clone_expandos, xml_first_last_child, xml_has_child_nodes, xml_idmap, xml_ignore_comments, xml_ignore_white, xml_insert_before, xml_inspect_createmethods, xml_inspect_doctype, xml_inspect_parsexml, xml_inspect_xmldecl, xml_namespaces, xml_parent_and_child, xml_remove_node, xml_reparenting, xml_siblings, xml_to_string, xml_to_string_comment, xml_unescaping, xmlnode_proto, xml_load, xml_socket, xml_socket_close_in_handler, xml_socket_on_data, xml_socket_segmented, xml_getbytes, swf5_xml_event_handler_context -->

Last updated: 2026-02-15

## Status: ALL PHASES COMPLETE

All 7 phases have been implemented. 24 out of 26 active XML tests pass (92%).

### Implementation Commits
- `c8c38b1` — Implement XML/XMLNode runtime support (phases 1-5) and add glob test filtering
- `73a7b45` — Fix XML runtime bugs: memory allocator mismatches, reparenting, ignoreWhite, idMap, namespaces
- `733a70e` — Fix regression: restrict varToStringBuf toString to XML nodes only
- `0778863` — Fix actionPushRegister, actionNewObject _global lookup, CallMethod own_props, and XML namespace scanning

### Current Test Results

| Test | Lines | Status |
|------|-------|--------|
| xml | 15/15 | **PASS** |
| xml_append_child | 28/28 | **PASS** |
| xml_append_child_with_parent | 20/20 | **PASS** |
| xml_attributes_read | 4/4 | **PASS** |
| xml_cdata | 11/11 | **PASS** |
| xml_child_nodes_edge_cases | 3/4 | output_mismatch (1 line off) |
| xml_clone_expandos | 19/19 | **PASS** |
| xml_first_last_child | 8/8 | **PASS** |
| xml_has_child_nodes | 3/3 | **PASS** |
| xml_idmap | 21/21 | **PASS** |
| xml_ignore_comments | 21/21 | **PASS** |
| xml_ignore_white | 34/34 | **PASS** |
| xml_insert_before | 20/20 | **PASS** |
| xml_inspect_createmethods | 15/15 | **PASS** |
| xml_inspect_doctype | 7/7 | **PASS** |
| xml_inspect_parsexml | 62/62 | **PASS** |
| xml_inspect_xmldecl | 7/7 | **PASS** |
| xml_namespaces | 203/203 | **PASS** |
| xml_parent_and_child | 5/5 | **PASS** |
| xml_remove_node | 22/22 | **PASS** |
| xml_reparenting | 14/14 | **PASS** |
| xml_siblings | 10/10 | **PASS** |
| xml_to_string | 11/13 | output_mismatch (2 lines off) |
| xml_to_string_comment | 1/1 | **PASS** |
| xml_unescaping | 23/23 | **PASS** |
| xmlnode_proto | 1/1 | **PASS** |
| **Total Active** | **587/589** | **24/26 PASS** |

### Remaining Issues (2 tests)

1. **xml_to_string** (11/13) — 2 lines off, likely an entity escaping or whitespace edge case in serialization
2. **xml_child_nodes_edge_cases** (3/4) — 1 line off, likely a toString or childNodes mutation edge case

### Deferred Tests (7 tests, network-dependent)
- xml_load, xml_socket, xml_socket_close_in_handler, xml_socket_on_data, xml_socket_segmented — need network
- xml_getbytes (9/17) — needs XML.load() for getBytesLoaded/getBytesTotal
- swf5_xml_event_handler_context — needs loadMovie

---

## Original Plan (preserved for reference)

The original plan below is preserved for architectural documentation purposes. All phases were implemented.

## Test Inventory (33 tests)

### Active Tests — Core XML DOM (26 tests)

| Test | Lines | Current Match | Phase |
|------|-------|--------------|-------|
| `xml` | 15 | 1 (6.7%) | 1 |
| `xml_inspect_createmethods` | 15 | 0 (0%) | 1 |
| `xml_inspect_parsexml` | 62 | 2 (3.2%) | 1 |
| `xml_parent_and_child` | 5 | 3 (60%) | 1 |
| `xml_has_child_nodes` | 3 | 0 (0%) | 1 |
| `xml_first_last_child` | 8 | 6 (75%) | 2 |
| `xml_siblings` | 10 | 6 (60%) | 2 |
| `xml_append_child` | 28 | 16 (57%) | 2 |
| `xml_append_child_with_parent` | 20 | 8 (40%) | 2 |
| `xml_insert_before` | 20 | 8 (40%) | 2 |
| `xml_remove_node` | 22 | 7 (31.8%) | 2 |
| `xml_child_nodes_edge_cases` | 4 | 0 (0%) | 2+3 |
| `xml_reparenting` | 14 | 0 (0%) | 2+3 |
| `xml_to_string` | 13 | 0 (0%) | 3 |
| `xml_to_string_comment` | 1 | 0 (0%) | 3 |
| `xml_unescaping` | 23 | 0 (0%) | 3+4 |
| `xml_cdata` | 11 | 5 (45.5%) | 4 |
| `xml_ignore_comments` | 21 | 0 (0%) | 4 |
| `xml_ignore_white` | 34 | 13 (38.2%) | 4 |
| `xml_inspect_doctype` | 7 | 1 (14.3%) | 4 |
| `xml_inspect_xmldecl` | 7 | 1 (14.3%) | 4 |
| `xml_attributes_read` | 4 | 1 (25%) | 5 |
| `xml_clone_expandos` | 19 | 10 (52.6%) | 5 |
| `xml_idmap` | 21 | 2 (9.5%) | 6 |
| `xmlnode_proto` | 1 | 0 (0%) | 6 |
| `xml_namespaces` | 203 | 8 (3.9%) | 7 |

### Deferred Tests — Network-Dependent (7 tests)

| Test | Notes | In ignored_tests.txt? |
|------|-------|-----------------------|
| `xml_load` | Needs HTTP `XML.load()` | Yes |
| `xml_socket` | Needs `XMLSocket` | Yes |
| `xml_socket_close_in_handler` | Needs `XMLSocket` | Yes |
| `xml_socket_on_data` | Needs `XMLSocket` | Yes |
| `xml_socket_segmented` | Needs `XMLSocket` | Yes |
| `xml_getbytes` | Needs `XML.load()` for `getBytesLoaded`/`getBytesTotal` | **No — should be added** |
| `swf5_xml_event_handler_context` | Needs `loadMovie` (not actually XML) | **No — should be added** |

**Action item**: Add `xml_getbytes` and `swf5_xml_event_handler_context` to `ignored_tests.txt`.

---

## Internal Data Model

XML nodes are stored as ASObjects with special properties. No new type tag is needed — XML objects use `ACTION_STACK_VALUE_OBJECT` like TextFormat, Error, etc.

### XMLNode Internal Properties

Each XML node is an ASObject with these properties set during construction:

```
nodeType        (Number)     1 = element, 3 = text
nodeName        (String)     tag name for elements, null for text nodes
nodeValue       (String)     text content for text nodes, null for elements
parentNode      (Object)     reference to parent node, null for roots
firstChild      (Object)     first child node, null if empty
lastChild       (Object)     last child node, null if empty
previousSibling (Object)     previous sibling, null for first child
nextSibling     (Object)     next sibling, null for last child
childNodes      (Array)      ASArray of child nodes
attributes      (Object)     ASObject of attribute name→value pairs (elements only)
```

**Critical**: Properties that have no value must be **`null`**, not `undefined`. Many current test failures are `undefined` vs `null`.

### XML Document Properties (on XML objects, not XMLNode)

```
xmlDecl         (String)     XML declaration string or undefined
docTypeDecl     (String)     DOCTYPE string or undefined
ignoreWhite     (Boolean)    false by default, strip whitespace-only text nodes during parse
idMap           (Object)     maps id attribute values to their nodes
status          (Number)     0 = no error, various error codes
loaded          (Boolean)    undefined (no load attempted), true/false after load
contentType     (String)     "application/x-www-form-urlencoded"
```

### Prototype Chain

```
XML.prototype → XMLNode.prototype → Object.prototype
```

XML inherits from XMLNode. Both `new XML()` and `new XMLNode()` instances have access to the same DOM manipulation methods. XML additionally has `parseXML`, `createElement`, `createTextNode`, `xmlDecl`, `docTypeDecl`, `ignoreWhite`, `idMap`.

---

## Phase 1: XML/XMLNode Constructors + Core Properties + Parser

**Goal**: Register XML and XMLNode as global constructors with proper prototypes. Implement the XML parser to build a DOM tree from an XML string. Implement core read-only properties.

### What the tests expect

From `xml`, the test does `new XML("<test></test>")` and inspects:
- `nodeType` → `1`
- `nodeName` → `null`
- `nodeValue` → `null`
- `localName` → `null` (Phase 7)
- `prefix` → `null` (Phase 7)
- `childNodes` iteration → shows child element with `nodeType=1, nodeName="test"`, which itself has no children

From `xml_inspect_createmethods`, the test uses `createElement("test")` and `createTextNode("This is a test")`, then `appendChild` to build a tree, and inspects `nodeType`, `nodeName`, `nodeValue`, `attributes` (must be defined, not undefined), `childNodes.length`.

From `xml_inspect_parsexml`, the test creates `new XML()` (empty, 0 children), calls `parseXML("<test>...</test>Here's more text.")` which replaces content (2 children: element + text). Calling `parseXML` again replaces again, and old children get `parentNode = null`.

### Implementation

#### 1a. Static globals and prototype initialization

```c
static ASFunction g_xml_constructor;
static ASFunction g_xmlnode_constructor;
static int g_xml_constructor_init = 0;
static ASObject* g_xmlnode_prototype = NULL;

static void initXMLPrototype(SWFAppContext* app_context);
```

#### 1b. XMLNode constructor: `new XMLNode(type, name)`

Creates a node with:
- `nodeType` = arg 0 (number, typically 1 or 3)
- `nodeName` = arg 1 (string for elements, null for text)
- `nodeValue` = null (for elements; text nodes set this to arg 1 content)
- `parentNode` = null
- `firstChild` = null
- `lastChild` = null
- `previousSibling` = null
- `nextSibling` = null
- `childNodes` = empty ASArray
- `attributes` = new ASObject (empty)
- `__proto__` → XMLNode.prototype

#### 1c. XML constructor: `new XML()` or `new XML(xmlString)`

- Creates an XMLNode with nodeType=1, nodeName=null, nodeValue=null
- Sets `__proto__` → XML.prototype (which inherits from XMLNode.prototype)
- Sets XML-specific defaults: `ignoreWhite=false`, `idMap=new ASObject`, `contentType="application/x-www-form-urlencoded"`, `status=0`
- If a string argument is provided, calls `parseXML()` on it

#### 1d. XML parser (`parseXML`)

A state-machine tokenizer that handles:
- Opening tags: `<tagName attr="val">` → create element node (nodeType=1), push onto stack
- Closing tags: `</tagName>` → pop stack
- Self-closing tags: `<tagName />` → create element, don't push
- Text content between tags → create text node (nodeType=3)
- Entity unescaping: `&amp;` → `&`, `&lt;` → `<`, `&gt;` → `>`, `&apos;` → `'`, `&quot;` → `"`
- Unknown entities pass through literally (e.g., `&thing;` stays as `&thing;`)
- Attribute parsing: `name="value"` or `name='value'`

Phase 1 parser can skip CDATA, comments, DOCTYPE, xmlDecl — those are added in Phase 4.

When `parseXML` is called on an existing XML object:
1. Old children get `parentNode = null` (orphaned)
2. Children cleared
3. Re-parse from new string

#### 1e. Methods on XMLNode.prototype (Phase 1 subset)

| Method | Implementation |
|--------|---------------|
| `hasChildNodes()` | Return `childNodes.length > 0` |

#### 1f. Methods on XML.prototype (Phase 1 subset)

| Method | Implementation |
|--------|---------------|
| `parseXML(text)` | Clear children, run parser |
| `createElement(name)` | Create XMLNode(1, name) |
| `createTextNode(text)` | Create XMLNode(3, null) with nodeValue=text |

#### 1g. Registration

In `GetVariable` handler, add cases for `"XML"` and `"XMLNode"`.
In `_global` initialization, register both constructors.
In `actionNewObject`, add cases for `"XML"` and `"XMLNode"`.

### Tests fixed by Phase 1

- **xml**: nodeType/nodeName/nodeValue work, childNodes iteration works
- **xml_inspect_createmethods**: createElement/createTextNode + appendChild (needs Phase 2 too)
- **xml_inspect_parsexml**: parseXML with clear-and-reparse behavior
- **xml_parent_and_child**: parentNode set correctly after appendChild (needs Phase 2 too)
- **xml_has_child_nodes**: hasChildNodes() method

**Estimated improvement**: ~5 tests significantly improved, ~3 reaching 100%

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=xml --diff --verbose
python3 ruffle-tests/verify_output.py --test=xml_inspect_parsexml --diff --verbose
python3 ruffle-tests/verify_output.py --test=xml_has_child_nodes --diff --verbose
```

---

## Phase 2: Tree Manipulation — appendChild, removeNode, insertBefore

**Goal**: Implement the DOM tree manipulation methods that maintain parent/child/sibling links correctly.

### Key behaviors

#### appendChild(child)
1. If `child` already has a `parentNode`, remove it from its old parent first (call removeNode internally)
2. If parent has existing children: set `lastChild.nextSibling = child`, `child.previousSibling = lastChild`
3. Set `child.parentNode = this`, update `this.lastChild = child`
4. If first child: set `this.firstChild = child` too
5. Append to `this.childNodes` array
6. **Circular reference prevention**: If `child` is an ancestor of `this`, the appendChild is a no-op

#### removeNode()
1. If `previousSibling` exists: `previousSibling.nextSibling = this.nextSibling`
2. If `nextSibling` exists: `nextSibling.previousSibling = this.previousSibling`
3. If parent's `firstChild === this`: parent.firstChild = this.nextSibling
4. If parent's `lastChild === this`: parent.lastChild = this.previousSibling
5. Remove from parent's `childNodes` array
6. Set `this.parentNode = null`, `this.previousSibling = null`, `this.nextSibling = null`

#### insertBefore(newChild, refChild)
1. If `newChild` already has a parent, remove it from old parent first
2. Insert `newChild` before `refChild` in the childNodes array
3. Link siblings: `newChild.previousSibling = refChild.previousSibling`, `newChild.nextSibling = refChild`
4. If `refChild.previousSibling` exists: `refChild.previousSibling.nextSibling = newChild`
5. `refChild.previousSibling = newChild`
6. If `refChild === parent.firstChild`: parent.firstChild = newChild
7. Set `newChild.parentNode = this`

### Tests fixed by Phase 2

- **xml_append_child**: Full appendChild with sibling/parent verification → should reach ~100%
- **xml_append_child_with_parent**: Re-parenting behavior → should reach ~100%
- **xml_insert_before**: insertBefore with re-parenting → should reach ~100%
- **xml_remove_node**: removeNode with sibling repair → should reach ~100%
- **xml_first_last_child**: firstChild/lastChild null vs node → should reach 100%
- **xml_siblings**: previousSibling/nextSibling chain → should reach 100%
- **xml_reparenting**: Cross-document reparenting + circular prevention → should reach 100%
- **xml_child_nodes_edge_cases**: Live childNodes array after mutations → needs toString (Phase 3)

**Estimated improvement**: ~7 tests reaching 100%, ~2 more significantly improved

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=xml_append_child --diff --verbose
python3 ruffle-tests/verify_output.py --test=xml_remove_node --diff --verbose
python3 ruffle-tests/verify_output.py --test=xml_reparenting --diff --verbose
python3 ruffle-tests/verify_output.py --test=xml_siblings --diff --verbose
```

---

## Phase 3: toString Serialization

**Goal**: Implement XML-to-string serialization so `trace(xmlNode)` and `xmlNode.toString()` produce correct XML output.

### Serialization rules

1. **Element node (nodeType=1)**:
   - Empty element (no children): `<tagName />`  (space before `/`)
   - Element with children: `<tagName>...children...</tagName>`
   - With attributes: `<tagName attr1="val1" attr2="val2">...</tagName>`
2. **Text node (nodeType=3)**: output `nodeValue` with entity escaping
3. **Entity escaping in output**: `&` → `&amp;`, `'` → `&apos;`, `"` → `&quot;`, `<` → `&lt;`, `>` → `&gt;`
4. **Document node (XML root)**: serialize all children concatenated (no wrapper tag since nodeName is null)
5. **Recursive**: each child is serialized recursively
6. **UTF-8**: pass through UTF-8 bytes unchanged

### Custom toString dispatch

The runtime's `toString` path (in `actionTrace`, `actionAdd2`, etc.) needs to check if an object is an XML/XMLNode instance and call the XML serializer instead of `"[type Object]"`.

Detection: Check if the object's `__proto__` chain includes `XMLNode.prototype`. A simple approach: add a hidden marker property (e.g., `__xml_node__ = true`) on XMLNode.prototype during initialization, and check for it.

### Tests fixed by Phase 3

- **xml_to_string**: Full serialization with entities, UTF-8, nesting → should reach 100%
- **xml_to_string_comment**: Comments stripped in output → needs Phase 4 for full fix, but serialization part works
- **xml_child_nodes_edge_cases**: `childNodes` elements serialized via toString → should reach 100%
- **xml_reparenting**: toString output verification → should reach 100%
- **xml_unescaping**: Partial — entity unescaping in parser (Phase 1) + re-escaping in toString

**Estimated improvement**: ~3 tests reaching 100%, several more improved

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=xml_to_string --diff --verbose
python3 ruffle-tests/verify_output.py --test=xml_child_nodes_edge_cases --diff --verbose
python3 ruffle-tests/verify_output.py --test=xml_unescaping --diff --verbose
```

---

## Phase 4: Parser Features — CDATA, Comments, DOCTYPE, xmlDecl, ignoreWhite

**Goal**: Extend the XML parser to handle special constructs.

### CDATA sections

`<![CDATA[content here]]>` → create text node (nodeType=3) with `nodeValue = "content here"`. No entity unescaping inside CDATA. The `toString()` of this text node is just the plain text (no CDATA markers in output).

### Comment stripping

`<!-- comment text -->` → skip entirely, do not create any node.

### DOCTYPE extraction

`<!DOCTYPE name>` or `<!DOCTYPE name SYSTEM "...">` → store the full declaration (including `<!DOCTYPE` and `>`) in `this.docTypeDecl`. Do not create a node.

### XML declaration extraction

`<?xml version="1.0" encoding="utf-8"?>` → store the full declaration (including `<?xml` and `?>`) in `this.xmlDecl`. Do not create a node.

### ignoreWhite

When `this.ignoreWhite === true` during `parseXML`:
- After creating a text node, check if `nodeValue` consists entirely of whitespace (`\t`, `\n`, `\r`, ` `)
- If so, discard the text node (don't add to tree)
- If the text contains any non-whitespace character (even one), keep it

### Tests fixed by Phase 4

- **xml_cdata**: CDATA creates text nodes, toString strips CDATA markers → should reach 100%
- **xml_ignore_comments**: Comments stripped, tree navigation works → should reach 100%
- **xml_ignore_white**: Whitespace text nodes stripped when ignoreWhite=true → should reach 100%
- **xml_inspect_doctype**: docTypeDecl property populated → should reach 100%
- **xml_inspect_xmldecl**: xmlDecl property populated → should reach 100%
- **xml_to_string_comment**: Comments stripped → should reach 100%
- **xml_unescaping**: Should now be 100% with parser + serializer combined

**Estimated improvement**: ~7 tests reaching 100%

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=xml_cdata --diff --verbose
python3 ruffle-tests/verify_output.py --test=xml_ignore_comments --diff --verbose
python3 ruffle-tests/verify_output.py --test=xml_ignore_white --diff --verbose
python3 ruffle-tests/verify_output.py --test=xml_inspect_doctype --diff --verbose
python3 ruffle-tests/verify_output.py --test=xml_unescaping --diff --verbose
```

---

## Phase 5: Attributes + cloneNode

**Goal**: Implement attribute parsing/access and deep/shallow node cloning.

### Attributes

During XML parsing, when encountering `<tag attr1="val1" attr2="val2">`:
1. Parse attribute name-value pairs
2. Store on the element's `attributes` ASObject
3. Entity-unescape attribute values

Reading `node.attributes.attrName` returns the string value.
`node.attributes` on text nodes should still be an ASObject (but empty).

### cloneNode(deep)

- `cloneNode(false)` or `cloneNode()` (default=false): Creates a new node with same `nodeType`, `nodeName`, `nodeValue`, same `attributes` (shallow copy of attribute object), but **no children** and **no parent/sibling links**. Custom expando properties are NOT copied.
- `cloneNode(true)`: Same as shallow, but recursively clone all children and append them.

### Indexed child access (`node[0]`, `node[1]`, etc.)

The `xml_ignore_comments` test uses `my_xml[0]`, `my_xml[1]`, etc. to access children by index. This is equivalent to `node.childNodes[0]`. In `actionGetMember`, when the property name is a number on an XML node, redirect to `childNodes[index]`.

### Tests fixed by Phase 5

- **xml_attributes_read**: Attribute access on parsed elements → should reach 100%
- **xml_clone_expandos**: cloneNode shallow/deep, expando non-copying → should reach 100%

**Estimated improvement**: ~2 tests reaching 100%

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=xml_attributes_read --diff --verbose
python3 ruffle-tests/verify_output.py --test=xml_clone_expandos --diff --verbose
python3 ruffle-tests/verify_output.py --test=xml_ignore_comments --diff --verbose
```

---

## Phase 6: idMap + XMLNode Prototype Chain

**Goal**: Implement the `idMap` property and ensure XMLNode.prototype is properly accessible for subclassing.

### idMap

The XML document maintains an `idMap` ASObject that maps `id` attribute values to their corresponding nodes:
1. During `parseXML`, whenever an element has an `id` attribute, set `idMap[id_value] = node`
2. During `appendChild` of a node with an `id` attribute, update `idMap`
3. `parseXML` does NOT clear idMap — new entries merge with existing ones
4. Expando properties set directly on `idMap` persist across `parseXML` calls

### XMLNode prototype accessibility

The `xmlnode_proto` test does:
1. Gets `XMLNode.prototype`
2. Assigns `CustomXMLNode.prototype = new XMLNode.prototype`
3. Creates instance and calls inherited method
4. This requires `XMLNode` to be a proper global constructor with an accessible `prototype`

### Tests fixed by Phase 6

- **xml_idmap**: idMap populated from `id` attributes, merging, expandos → should reach ~100%
- **xmlnode_proto**: XMLNode prototype chain inheritance → should reach 100%

**Estimated improvement**: ~2 tests reaching 100%

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=xml_idmap --diff --verbose
python3 ruffle-tests/verify_output.py --test=xmlnode_proto --diff --verbose
```

---

## Phase 7: Namespace Support

**Goal**: Implement XML namespace features — the most complex single test (203 lines).

### Namespace properties on XMLNode

- `prefix`: The part before `:` in the tag name (e.g., `test` in `test:test10`). Empty string `""` if no prefix.
- `localName`: The part after `:` (e.g., `test10` in `test:test10`). If no prefix, same as `nodeName`.
- `namespaceURI`: The resolved namespace URI for this node's prefix, looked up through ancestor `xmlns:prefix` attributes.

### Namespace resolution

When parsing an element with `xmlns="uri"` or `xmlns:prefix="uri"` attributes:
- These define namespace bindings that apply to the element and all its descendants
- Default namespace (`xmlns="uri"`) applies to unprefixed elements
- Prefixed namespace (`xmlns:prefix="uri"`) applies to elements with that prefix

Resolution algorithm for `namespaceURI`:
1. If node has a prefix, look for `xmlns:prefix` in own attributes, then walk up ancestors
2. If node has no prefix, look for `xmlns` (default namespace) in own attributes, then walk up ancestors
3. If not found, return `null`? (Test output shows empty string `""` for some and `null` for others — need to verify)

### Methods

- `getNamespaceForPrefix(prefix)`: Walk up the tree looking for `xmlns:prefix` attribute. Return the URI or `null`.
- `getPrefixForNamespace(uri)`: Walk up the tree looking for any `xmlns:prefix` attribute whose value matches `uri`. Return the prefix or `null`.

### Tests fixed by Phase 7

- **xml_namespaces**: Full namespace test (203 lines) → should reach ~100%

**Estimated improvement**: 1 test reaching ~100% (but 203 lines — big line count impact)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=xml_namespaces --diff --verbose
```

---

## Implementation Details

### Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | XML/XMLNode constructor registration, prototype methods, parser, toString, all DOM methods |
| `ruffle-tests/ignored_tests.txt` | Add `xml_getbytes` and `swf5_xml_event_handler_context` |

No recompiler changes are needed. No new files needed — everything goes in `action.c` following the existing pattern for TextFormat, Date, Error, etc.

### Constructor Registration Pattern

Following the established pattern in `action.c`:

1. **Static globals**: `g_xml_constructor`, `g_xmlnode_constructor`, `g_xml_constructor_init`
2. **`GetVariable` handler**: Cases for `"XML"` (3 chars) and `"XMLNode"` (7 chars)
3. **`_global` registration**: Set properties on global_object
4. **`actionNewObject` handler**: Cases for `"XML"` and `"XMLNode"` constructor names

### XML toString Dispatch

In the runtime's string conversion path (wherever `"[type Object]"` would be produced), check for XML nodes by looking for a `__xml_node__` marker or checking the prototype chain, and call the XML serializer instead.

### Parser Design

Simple state-machine parser, operating on a `const char*` input:

```
States: TEXT, TAG_OPEN, TAG_NAME, TAG_CLOSE, ATTR_NAME, ATTR_VALUE,
        CDATA, COMMENT, DOCTYPE, XML_DECL
```

Key parse loop:
1. Start in TEXT state
2. `<` → check next char:
   - `/` → closing tag (TAG_CLOSE)
   - `!` → check for `--` (COMMENT), `[CDATA[` (CDATA), `DOCTYPE` (DOCTYPE)
   - `?` → XML_DECL
   - else → opening tag (TAG_OPEN → TAG_NAME)
3. In TAG_NAME: read tag name, then parse attributes, then `>` or `/>`
4. In TEXT: accumulate text until `<`, create text node from accumulated text

Entity unescaping during text/attribute value parsing:
- `&amp;` → `&`
- `&lt;` → `<`
- `&gt;` → `>`
- `&apos;` → `'`
- `&quot;` → `"`
- `&unknown;` → `&unknown;` (pass through)

### Memory Management

XML nodes are ASObjects managed by the existing object allocator. The tree structure is maintained via property references (parentNode, firstChild, etc.). No special memory management beyond what ASObjects already provide.

---

## Implementation Priority and Dependencies

```
Phase 1 (Constructors + Parser + Core Props)
    │
    ├──→ Phase 2 (Tree Manipulation)
    │       │
    │       ├──→ Phase 3 (toString)
    │       │       │
    │       │       ├──→ Phase 4 (Parser Features)
    │       │       │
    │       │       └──→ Phase 5 (Attributes + Clone)
    │       │               │
    │       │               └──→ Phase 6 (idMap + Prototype)
    │       │
    │       └──→ Phase 7 (Namespaces) [independent of 3-6, only needs 1+2]
    │
    └──→ Phase 6 partial (XMLNode prototype accessibility)
```

### Estimated Test Impact

| Phase | Description | Tests Fixed | Cumulative Tests | Lines Fixed (est.) |
|-------|-------------|-------------|-----------------|-------------------|
| 1 | Constructors + Parser + Core Props | ~3 | ~3 | ~80 |
| 2 | Tree Manipulation | ~7 | ~10 | ~120 |
| 3 | toString Serialization | ~3 | ~13 | ~30 |
| 4 | CDATA, Comments, DOCTYPE, ignoreWhite | ~7 | ~20 | ~95 |
| 5 | Attributes + cloneNode | ~2 | ~22 | ~25 |
| 6 | idMap + XMLNode Prototype | ~2 | ~24 | ~22 |
| 7 | Namespaces | ~1 | ~25 | ~195 |
| **Total** | | **~25/26 active** | | **~567/589 lines** |

Skipped: `xml_getbytes` (needs load), `swf5_xml_event_handler_context` (needs loadMovie) = 2 tests not fixable.

### Filtered Pass Rate Impact

With 26 active XML tests and ~491 total filtered tests:
- **Phase 1-2**: ~10 new passes → ~2% filtered pass rate increase
- **Phase 1-4**: ~20 new passes → ~4% filtered pass rate increase
- **Phase 1-7**: ~25 new passes → ~5% filtered pass rate increase

---

## Quick Win Estimate

**Phases 1+2** (Constructors + Parser + Tree Manipulation) would fix ~10 tests and are the foundation everything else builds on. The parser is the biggest piece of work but is needed for almost every test. Phases 3-7 are incremental additions on top of the working parser and DOM.

**Biggest bang-for-buck single phase**: Phase 4 (CDATA, Comments, DOCTYPE, ignoreWhite) fixes ~7 tests with relatively simple parser extensions.

**Biggest single-test line impact**: Phase 7 (Namespaces) — the `xml_namespaces` test alone has 203 expected lines.
