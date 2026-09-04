package {
	import flash.display.MovieClip;

	// Child movie of avm2_parent_child_static_text (see README.md). It carries
	// no ActionScript of its own beyond this ctor trace: everything graded
	// lives in the DefineFont3 + DefineText + PlaceObject2 that
	// build_statictext.py splices into its frame 1 — glyph code 'B', colour
	// blue, pen x 4200 twips (210px), all three different from the parent's.
	public class Child extends MovieClip {
		public function Child() {
			trace("chd:ctor");
		}
	}
}
