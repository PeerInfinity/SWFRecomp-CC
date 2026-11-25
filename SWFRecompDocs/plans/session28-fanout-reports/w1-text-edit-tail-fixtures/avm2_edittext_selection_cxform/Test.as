package {
import flash.display.*;
import flash.events.Event;
import flash.geom.ColorTransform;
import flash.text.*;

// s28 w1-text-edit-tail (c): AS3 twin of create_test_swf.py (the hand-assembled
// SWF is the one to capture; this is the readable program and an mxmlc route).
// Reworked from s27 w2-avm2-text-tail: everything runs on ADDED_TO_STAGE, so the
// SWF also works as a Loader child under tools/flash-oracle/run_image.py.
[SWF(width="120", height="150", backgroundColor="#FFFFFF")]
public class Test extends Sprite {
    [Embed(source="TestFont.ttf", fontName="TestFont", embedAsCFF="false", unicodeRange="U+0020-U+007E")]
    private var TestFont:Class;
    private var done:Boolean = false;

    public function Test() {
        addEventListener(Event.ADDED_TO_STAGE, init);
        if (stage) dispatchEvent(new Event(Event.ADDED_TO_STAGE));
    }

    private function init(e:Event):void {
        if (done) return;
        done = true;
        row(this, 0, true);
        var t1:TextField = row(this, 30, true);
        t1.transform.colorTransform = new ColorTransform(0, 0, 0, 1, 255, 0, 0, 0);
        var t2:TextField = row(this, 60, true);
        t2.transform.colorTransform = new ColorTransform(1, 1, 1, 1, 0, 0, 255, 0);
        var holder:Sprite = new Sprite();
        addChild(holder);
        holder.transform.colorTransform = new ColorTransform(0, 0, 0, 1, 255, 0, 255, 0);
        row(holder, 90, true);
        var t4:TextField = row(this, 120, false);
        t4.transform.colorTransform = new ColorTransform(0, 0, 0, 1, 0, 200, 0, 0);
        stage.focus = t4;
        trace("focus=" + (stage.focus == t4));
        trace("sel=" + t1.selectionBeginIndex + "," + t1.selectionEndIndex);
    }

    private function row(parent:DisplayObjectContainer, y:Number, always:Boolean):TextField {
        var text:TextField = new TextField();
        text.embedFonts = true;
        text.defaultTextFormat = new TextFormat("TestFont", 20);
        text.x = 0;
        text.y = y;
        text.width = 120;
        text.height = 28;
        text.text = "ababa";
        text.alwaysShowSelection = always;
        parent.addChild(text);
        text.setSelection(1, 4);
        return text;
    }
}
}
