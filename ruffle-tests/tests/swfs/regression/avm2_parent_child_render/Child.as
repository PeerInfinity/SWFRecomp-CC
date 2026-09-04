package {
	import flash.display.Sprite;

	// Child movie of avm2_parent_child_render (see README.md). It defines
	// exactly ONE shape character — a blue circle at stage (300,200) r=60 —
	// so its geometry sits at vertex offset 0 and colour index 0 of its OWN
	// arrays: the same index-0 collision avm1_parent_child_render uses, which
	// makes a read against the ROOT's arrays land on real, in-bounds data (the
	// parent's red circle) rather than on garbage.
	public class Child extends Sprite {
		[Embed(source="child_art.svg")]
		private var Art:Class;

		public function Child() {
			addChild(new Art() as Sprite);
			trace("chd:ctor");
		}
	}
}
