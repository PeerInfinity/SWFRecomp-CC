// Collectable E4X (seedling-wasm-leak L1). E4X used to be immortal: every
// node was a GC root and every XML/XMLList wrapper was pinned, so a game that
// re-parses a level document per room swap (Seedling) retained every
// document and every query list forever. test_env.json pins a small arena
// (SWF_HEAP_MB): immortal E4X exhausts it before "done"; collectable E4X
// keeps the floor flat.
//
// The live half (run under AVM2_GC_STRESS=1 for a collect every tick): a
// document held only by a member must survive every collection with its
// identity (a.x[0] === a.x[0] across ticks), parent links, namespaces,
// attributes, a setNotification closure, a child reached only through a
// detached-subtree wrapper (its parent must stay navigable), and a list
// whose target object is otherwise unreachable.
//
// Build: see build_swf.sh (mxmlc).
package {
	import flash.display.MovieClip;
	import flash.events.Event;

	public class Test extends MovieClip {
		private var tick:int = 0;
		private var doc:XML;
		private var firstRoom:XML;
		private var secondRoom:XML;
		private var deepLeaf:XML;
		private var orphanLeaf:XML;
		private var attrList:XMLList;
		private var appended:XMLList;
		private var notes:int = 0;  // the closure only has to stay alive
		private var total:int = 0;

		public function Test() {
			trace("start");
			doc = build(7);
			firstRoom = doc.room[0];
			secondRoom = doc.room[1];
			deepLeaf = doc.room[2].tile.(@kind == "spike")[0];
			attrList = doc.room.@id;
			// Only a leaf of this document is held: the rest of its tree must
			// stay navigable through parent().
			orphanLeaf = build(3).room[4].tile[2];
			// A list whose only path to its target is the list itself.
			appended = makeTargetOnly();
			doc.setNotification(function (...args):void { notes++; });
			addEventListener(Event.ENTER_FRAME, onFrame);
		}

		private function makeTargetOnly():XMLList {
			var holder:XML = <holder><e>one</e></holder>;
			return holder.e;
		}

		private function build(k:int):XML {
			var s:String = "<level xmlns:g=\"urn:game\" name=\"L" + k + "\">";
			for (var r:int = 0; r < 12; r++) {
				s += "<room id=\"r" + r + "\" g:theme=\"cave\">";
				for (var t:int = 0; t < 12; t++) {
					s += "<tile x=\"" + t + "\" y=\"" + r + "\" kind=\"" + (t % 5 == 3 ? "spike" : "floor") + "\">t" + t + "</tile>";
				}
				s += "<g:note>room " + r + " of level " + k + "</g:note></room>";
			}
			return new XML(s + "</level>");
		}

		private function churn():void {
			for (var i:int = 0; i < 10; i++) {
				var x:XML = build(tick * 100 + i);
				var spikes:XMLList = x..tile.(@kind == "spike");
				var g:Namespace = x.namespace("g");
				total += spikes.length() + x.room.length() + x.room[3].g::note.toString().length;
				total += int(x.room.(@id == "r5").tile[4].@x);
			}
		}

		private function verify():void {
			var g:Namespace = new Namespace("urn:game");
			trace("  identity=" + (doc.room.(@id == "r1")[0] === secondRoom) + " " + (doc.room[0] === doc.room[0])
			      + " leafParent=" + deepLeaf.parent().@id + " leafRoot=" + (deepLeaf.parent().parent() === doc)
			      + " attrs=" + attrList.toXMLString().split("\n").join(",")
			      + " theme=" + firstRoom.@g::theme + " note=" + firstRoom.g::note
			      + " appended=" + appended.toXMLString() + " parent=" + appended[0].parent().name());
			trace("  orphanLeaf=" + orphanLeaf.toXMLString() + " room=" + orphanLeaf.parent().@id
			      + " level=" + orphanLeaf.parent().parent().@name
			      + " sibling=" + orphanLeaf.parent().parent().room[11].tile[11].@kind);
		}

		private function onFrame(e:Event):void {
			tick++;
			if (tick > 120) return;
			churn();
			if (tick == 5) {
				// Detach a room: the subtree lives on through firstRoom only.
				delete doc.room[0];
				trace("detached: rooms=" + doc.room.length() + " firstRoom.parent=" + firstRoom.parent());
				firstRoom.appendChild(<tile x="99" kind="new"/>);
				appended += <e>two</e>;
			}
			if (tick == 6) {
				doc.appendChild(<room id="r12"/>);
			}
			if (tick % 40 == 0 || tick == 1) {
				trace("tick " + tick + " total=" + total + " rooms=" + doc.room.length()
				      + " firstRoomTiles=" + firstRoom.tile.length());
				verify();
			}
			if (tick == 120) trace("done");
		}
	}
}
