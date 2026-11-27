package {
import flash.display.Sprite;
import flash.events.Event;
import flash.text.TextField;

// s30 w1-drift-smalls FLASH probe: how many <img> loads (=> unhandled #2044
// reports) does ONE htmlText parse start, per case? One case every 20 frames,
// so each case's async IOErrorEvent reports print before the next CASE line.
// Build: mxmlc -static-link-runtime-shared-libraries -default-frame-rate=30 Test.as -output test.swf
public class Test extends Sprite {
    private var cases:Array = [
        "A<img src='missing.jpg'>B",
        "A<img src=''>B",
        "A<img src='one.jpg'>B<img src='two.jpg'>C",
        "A<img src='a.jpg'><img src='a.jpg'>B",
        "A<img src='a.jpg' id='x'><img src='a.jpg'>B",
        "A<img src='a.jpg' width='7'><img src='a.jpg'>B",
        "A<img src='a.jpg' height='7'><img src='a.jpg' height='7'>B",
        "A<img src='a.jpg' hspace='7'><img src='a.jpg' hspace='7'>B",
        "A<img src='a.jpg' vspace='7'><img src='a.jpg' vspace='7'>B",
        "A<img src='a.jpg' checkPolicyFile='true'><img src='a.jpg' checkPolicyFile='true'>B",
        "<img src='a.jpg'><img src='b.jpg'>",
        "A<img src='missing.jpg'>X</img>B",
        "A<img src='missing.jpg' />B",
        "REPARSE"
    ];
    private var frame:int = 0;
    private var idx:int = 0;
    public function Test() { addEventListener(Event.ENTER_FRAME, tick); }
    private function tick(e:Event):void {
        if (frame++ % 20 != 0) return;
        if (idx >= cases.length) {
            trace("END");
            removeEventListener(Event.ENTER_FRAME, tick);
            return;
        }
        var html:String = cases[idx];
        var tf:TextField = new TextField();
        tf.width = 400; tf.height = 300; tf.multiline = true;
        addChild(tf);
        if (html == "REPARSE") {
            trace("CASE " + idx + " REPARSE first");
            tf.htmlText = "A<img src='missing.jpg'>B";
            var first:String = tf.htmlText;
            trace("CASE " + idx + " REPARSE second");
            tf.htmlText = first + " ";
        } else {
            trace("CASE " + idx + " " + html);
            tf.htmlText = html;
        }
        idx++;
    }
}
}
