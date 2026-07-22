package {
	import flash.display.Sprite;
	public class Grad extends Sprite {
		[Embed(source="grad.svg")]
		private var Art:Class;
		public function Grad() {
			addChild(new Art() as Sprite);
			trace("grad placed");
		}
	}
}
