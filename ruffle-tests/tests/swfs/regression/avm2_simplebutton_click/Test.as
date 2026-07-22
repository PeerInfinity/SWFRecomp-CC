package {
	import flash.display.Sprite;
	import flash.display.Shape;
	import flash.display.SimpleButton;
	import flash.events.MouseEvent;

	// Regression for AVM2 mouse hit-testing of a nested SimpleButton.
	//
	// A SimpleButton's visual/hit state children live in the btn_up/btn_hit
	// slots, NOT in the container render_list that mouse_pick / bounds walk. So
	// before the fix, mouse_pick found the button's self-bounds EMPTY and MISSED
	// it entirely: a click on the button dispatched nothing. This is exactly what
	// blocked Elephant Quest's frame1 preloader Play button (SimpleButton
	// 'playB', nested root -> preloader -> playB) from advancing on a click.
	//
	// mouse_pick now hit-tests a SimpleButton via its hitTestState (falling back
	// to the up state), inverse-mapping the stage point into the state's local
	// space, and returns the BUTTON as the pick target. A down+up on the same
	// target then dispatches "click" (which bubbles), so the button's own
	// addEventListener(MouseEvent.CLICK) handler fires.
	//
	// The button is nested one level deep (root -> container -> button) to prove
	// the pick descends through a container into the button and the click bubbles
	// back up to the button's listener. input.json clicks the button's centre
	// (stage px 160,125 = container (100,100) + hit rect centre (60,25)).
	public class Test extends Sprite {
		public function Test() {
			var up:Shape = mkRect(0x00ff00);
			var over:Shape = mkRect(0x0000ff);
			var down:Shape = mkRect(0xffff00);
			var hit:Shape = mkRect(0xff0000);
			var btn:SimpleButton = new SimpleButton(up, over, down, hit);

			var container:Sprite = new Sprite();
			container.x = 100;
			container.y = 100;
			container.addChild(btn);
			addChild(container);

			btn.addEventListener(MouseEvent.CLICK, onClick);
			trace("ready");
		}

		private function mkRect(color:uint):Shape {
			var s:Shape = new Shape();
			s.graphics.beginFill(color);
			s.graphics.drawRect(0, 0, 120, 50);
			s.graphics.endFill();
			return s;
		}

		private function onClick(e:MouseEvent):void {
			trace("CLICK ok target=" + (e.target is SimpleButton));
		}
	}
}
