// Intrinsic declaration so MTASC emits a normal `new Rando(...)` constructor
// call + method dispatch without needing a class body — the implementation is
// the native runtime builtin (SWFModernRuntime/src/actionmodern/rando.c).
intrinsic class Rando {
	function Rando(host:String, port:String, game:String, slot:String, password:String);
	function connect():Void;
	function isConnected():Boolean;
	function receivedItemsSize():Number;
	function receivedItem(i:Number):Number;
	function hasItem(id:Number):Boolean;
	function locationIsChecked(id:Number):Boolean;
	function sendLocation(id:Number):Void;
	function storyComplete():Void;
}
