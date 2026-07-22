package {
	import flash.display.Sprite;
	public class Probe extends Sprite {
		[Embed(source="probe.svg")]
		private var Art:Class;
		public function Probe() {
			var art:Sprite = new Art() as Sprite;
			addChild(art);
			trace("probe placed");
		}
	}
}
