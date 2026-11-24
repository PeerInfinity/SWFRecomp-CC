package {
import flash.display.*;
import flash.geom.ColorTransform;
import flash.text.*;

// s27 w2-avm2-text-tail item 3: is the EditText SELECTION BACKGROUND tinted by
// the field's (and its parents') colorTransform?
//   Ruffle edit_text.rs render_selection_background_for_line: draw_rect(color)
//   with NO colour transform (BLACK focused / GRAY 0x555555 unfocused), and
//   selected glyphs pushed with ColorTransform::IDENTITY (white, still under
//   the stacked parent transform).
//   SWFRecomp avm2_display.c avm2_render_text: the selection rects draw
//   through the field's concatenated cx slot (cxid), so they ARE tinted.
// Every row selects "bab" of "ababa" (setSelection(1, 4)).
//   row 0 (y=0):   control, unfocused + alwaysShowSelection, no tint  -> gray
//   row 1 (y=30):  unfocused, field cx = (0,0,0,1, 255,0,0,0)  (all red)
//   row 2 (y=60):  unfocused, field cx = (1,1,1,1, 0,0,255,0)  (+blue)
//   row 3 (y=90):  PARENT sprite cx = (0,0,0,1, 255,0,255,0), field untinted
//   row 4 (y=120): FOCUSED (stage.focus), field cx = (0,0,0,1, 0,200,0,0)
// Read each row's rect colour in the gaps between glyphs:
//   untinted -> 0x555555 (rows 0-3) / 0x000000 (row 4)
//   tinted   -> row1 0xFF0000, row2 0x5555FF, row3 0xFF00FF, row4 0x00C800
[SWF(width="120", height="150", backgroundColor="#FFFFFF")]
public class Test extends Sprite {
    [Embed(source="TestFont.ttf", fontName="TestFont", embedAsCFF="false", unicodeRange="U+0061-U+0064")]
    private var TestFont:Class;

    public function Test() {
        var t0:TextField = row(this, 0, true);

        var t1:TextField = row(this, 30, true);
        t1.transform.colorTransform = new ColorTransform(0, 0, 0, 1, 255, 0, 0, 0);

        var t2:TextField = row(this, 60, true);
        t2.transform.colorTransform = new ColorTransform(1, 1, 1, 1, 0, 0, 255, 0);

        var holder:Sprite = new Sprite();
        addChild(holder);
        holder.transform.colorTransform = new ColorTransform(0, 0, 0, 1, 255, 0, 255, 0);
        var t3:TextField = row(holder, 90, true);

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
