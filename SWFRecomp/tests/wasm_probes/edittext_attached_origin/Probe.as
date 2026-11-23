// edittext_attached_origin: a Flash-IDE-style EditText (embedded font, bounds
// min -2,-2 px, placed at +2,+2 inside exported sprite "lbl") attached six
// ways. Ruffle draws every bordered box with its top-left at the attach point
// (columns x=20 / x=130; rows y=20 / 70 / 120):
//   A (20,20)   into a createEmptyMovieClip buffer at (20,20), field untouched
//   B (130,20)  onto _root, field untouched
//   C (20,70)   into a buffer at (0,0), the attached clip moved, field touched
//   D (130,70)  onto _root, field touched
//   E (20,120)  two buffers deep, field untouched
//   F (130,120) into a buffer, field text set from AS
//   G (20,170)  into a buffer, field bound by variableName (clip.v = ...)
//   H (130,170) onto _root, field bound by variableName
//   I (20,220)  N's timeIndicator shape: attached "lblN" -> sprite "box" ->
//               UNNAMED field (variableName "txt"), into a buffer
//   J (130,220) the same shape attached onto _root
//   K (20,270)  N's actual use: like I, then AS moves the nested sprite
//               (timeMC.txtbox._y = ...): box._x/_y set from AS
//   L (130,270) K's shape attached onto _root
// s26: browser-WASM drew N's attached HUD fields 2 px up-left.
class Probe {
	static function main(mc) {
		var r = _root;
		r.createEmptyMovieClip("bufA", 1); r.bufA._x = 20; r.bufA._y = 20;
		r.bufA.attachMovie("lbl", "a", 1);
		r.attachMovie("lbl", "b", 2); r.b._x = 130; r.b._y = 20;
		r.createEmptyMovieClip("bufC", 3);
		r.bufC.attachMovie("lbl", "c", 1); r.bufC.c._x = 20; r.bufC.c._y = 70;
		var t = r.bufC.c.fld.text;
		r.attachMovie("lbl", "d", 4); r.d._x = 130; r.d._y = 70;
		t += r.d.fld.text;
		r.createEmptyMovieClip("bufE", 5); r.bufE._x = 20; r.bufE._y = 120;
		r.bufE.createEmptyMovieClip("inner", 1);
		r.bufE.inner.attachMovie("lbl", "e", 1);
		r.createEmptyMovieClip("bufF", 6); r.bufF._x = 130; r.bufF._y = 120;
		r.bufF.attachMovie("lbl", "f", 1);
		r.bufF.f.fld.text = "gH";
		r.createEmptyMovieClip("bufG", 7); r.bufG._x = 20; r.bufG._y = 170;
		r.bufG.attachMovie("lblv", "g", 1);
		r.bufG.g.v = "Hg";
		r.attachMovie("lblv", "h", 8); r.h._x = 130; r.h._y = 170;
		r.h.v = "Hg";
		r.createEmptyMovieClip("bufI", 9); r.bufI._x = 20; r.bufI._y = 220;
		r.bufI.attachMovie("lblN", "i", 1);
		r.bufI.i.box.txt = "Hg";
		r.attachMovie("lblN", "j", 10); r.j._x = 130; r.j._y = 220;
		r.j.box.txt = "Hg";
		r.createEmptyMovieClip("bufK", 11); r.bufK._x = 20; r.bufK._y = 260;
		r.bufK.attachMovie("lblN", "k", 1);
		r.bufK.k.box._x = 0; r.bufK.k.box._y = 10;
		r.bufK.k.box.txt = "Hg";
		r.attachMovie("lblN", "l", 12); r.l._x = 130; r.l._y = 260;
		r.l.box._x = 0; r.l.box._y = 10;
		r.l.box.txt = "Hg";
		trace("TO: touched=" + t + " f=" + r.bufF.f.fld.text);
	}
}
