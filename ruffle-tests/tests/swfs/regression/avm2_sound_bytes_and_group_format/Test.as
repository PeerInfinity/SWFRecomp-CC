package {
    import flash.display.Sprite;
    import flash.events.Event;
    import flash.events.ProgressEvent;
    import flash.media.Sound;
    import flash.net.URLRequest;
    import flash.text.engine.*;
    import flash.utils.ByteArray;

    // Pins the ungraded halves of two s21 ports (w2-tt-b):
    //  - Sound.loadCompressedDataFromByteArray: synchronous progress + id3
    //    events inside the call, the ByteArray position advance, the no-op
    //    once Loaded, and load(null) leaving the state at New.
    //  - TextBlock.createTextLine over a GroupElement: a null-text
    //    TextElement without a format is ignored, a GraphicElement adds no
    //    text, a text-bearing element without a format is #2175.
    public class Test extends Sprite {
        [Embed(source = "sound.mp3", mimeType = "application/octet-stream")]
        public static var Mp3Bytes:Class;

        public function Test() {
            soundRows();
            textRows();
            trace("Finished");
        }

        private function listen(s:Sound, tag:String):void {
            var f:Function = function (e:Event):void {
                var extra:String = "";
                if (e is ProgressEvent) {
                    extra = " " + ProgressEvent(e).bytesLoaded + "/" + ProgressEvent(e).bytesTotal;
                }
                trace("  " + tag + " event " + e.type + extra);
            };
            s.addEventListener(Event.OPEN, f);
            s.addEventListener(ProgressEvent.PROGRESS, f);
            s.addEventListener(Event.ID3, f);
            s.addEventListener(Event.COMPLETE, f);
        }

        private function soundRows():void {
            var ba:ByteArray = new Mp3Bytes();
            var total:uint = ba.length;
            // Prefix 3 junk bytes so the position start is observable.
            var padded:ByteArray = new ByteArray();
            padded.writeByte(1);
            padded.writeByte(2);
            padded.writeByte(3);
            padded.writeBytes(ba);
            padded.position = 3;

            trace("A: bytes load");
            var s:Sound = new Sound();
            listen(s, "A");
            trace("  before");
            s.loadCompressedDataFromByteArray(padded, total);
            trace("  after, position delta " + (padded.position - 3 - total));
            trace("  id3 is null: " + (s.id3 == null));

            trace("B: second bytes load is a no-op");
            padded.position = 3;
            s.loadCompressedDataFromByteArray(padded, total);
            trace("  position unchanged: " + (padded.position == 3));

            trace("C: load(null) keeps New");
            var s2:Sound = new Sound();
            try {
                s2.load(null);
                trace("  load(null) ok");
                s2.loadPCMFromByteArray(new ByteArray(), 0);
                trace("  pcm ok");
                s2.load(new URLRequest("missing.mp3"));
                trace("  load after pcm: no throw");
            } catch (e:Error) {
                trace("  " + e);
            }

            trace("D: short read");
            var s3:Sound = new Sound();
            var small:ByteArray = new ByteArray();
            small.writeByte(0);
            small.writeByte(0);
            small.position = 1;
            try {
                s3.loadCompressedDataFromByteArray(small, 2);
                trace("  no throw");
            } catch (e:Error) {
                trace("  " + e + " position " + small.position);
            }
        }

        // showLength=false where Flash and Ruffle disagree on the text model
        // (FP counts a GraphicElement as one U+FDEF, Ruffle as nothing).
        private function tryBlock(name:String, content:ContentElement,
                                  showLength:Boolean = true):void {
            trace(name);
            var line:TextLine = new TextBlock(content).createTextLine(null, 10000);
            trace("  line " + (line == null ? "null" : (showLength
                ? "rawTextLength " + line.rawTextLength : "created")));
        }

        private function textRows():void {
            tryBlock("E: group with null-text unformatted element",
                new GroupElement(new <ContentElement>[
                    new TextElement(null, null),
                    new TextElement("ab", new ElementFormat())
                ]));
            tryBlock("F: group with graphic between text",
                new GroupElement(new <ContentElement>[
                    new TextElement("ab", new ElementFormat()),
                    new GraphicElement(new Sprite(), 10, 10, null),
                    new TextElement("cd", new ElementFormat())
                ]), false);
            tryBlock("G: group with unformatted text",
                new GroupElement(new <ContentElement>[
                    new TextElement("ab", new ElementFormat()),
                    new TextElement("cd", null)
                ]));
        }
    }
}
