package {
	import flash.display.Sprite;
	import flash.ui.ContextMenu;
	import flash.ui.ContextMenuItem;

	// Regression for the flash.ui.ContextMenu / ContextMenuItem stubs that
	// Elephant Quest's SoundBox.initContextMenu builds at frame1 (a cosmetic
	// right-click menu). Before the ContextMenuItem stub existed this path threw
	// #1065 "ContextMenuItem is not defined" BEFORE MainTimeline.preloadIt(), so
	// the preloader never started and the stage stayed blank. Mirrors that exact
	// sequence: new ContextMenu -> hideBuiltInItems -> new ContextMenuItem(cap)
	// -> item.enabled = false -> customItems.push(item) -> this.contextMenu = menu.
	public class Test extends Sprite {
		public function Test() {
			var menu:ContextMenu = new ContextMenu();
			trace("menu created: " + (menu is ContextMenu));
			menu.hideBuiltInItems();
			var item:ContextMenuItem = new ContextMenuItem("Playing at armorgames.com");
			trace("item created: " + (item is ContextMenuItem));
			item.enabled = false;
			trace("push: " + menu.customItems.push(item));
			this.contextMenu = menu;
			trace("assigned contextMenu, no throw");
		}
	}
}
