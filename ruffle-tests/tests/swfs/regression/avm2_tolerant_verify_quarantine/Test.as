package {
	import flash.display.Sprite;

	// Regression net for the recompiler's TOLERANT PER-BODY VERIFY.
	//
	// `decoyBody()` below is hex-patched after compilation so its first
	// bytecode op becomes the UNDEFINED AVM2 opcode 0xf4 — exactly the
	// `betz`-obfuscator decoy that Elephant Quest hides in its dead body
	// 1309 (real AVM2 debug ops stop at 0xf3). Ruffle survives it via lazy
	// per-method verify; our recompiler verifies AOT, so it must QUARANTINE
	// only the offending body (emit a runtime-throw stub) and still emit &
	// run every OTHER body — NOT abort the whole ABC.
	//
	// `decoyBody()` is deliberately never invoked, so its quarantine stub is
	// never reached and the good traces below must all appear. If tolerant
	// verify ever regresses to a whole-file abort, output.txt goes empty and
	// this test fails loudly.  See SWFRecompDocs/plans/avm2-elephant-quest.md
	// (EQ-0) and abc_emit.cpp:2828 / swf.cpp per-body verify.
	public class Test extends Sprite {
		public function Test() {
			trace("good body A");
			trace("good body B: " + goodHelper());
		}

		public function goodHelper():String {
			return "helper-ran";
		}

		// Body hex-patched to opcode 0xf4 by create_test_swf.py. Never called.
		public function decoyBody():void {
			trace("DECOY SHOULD NEVER RUN");
		}
	}
}
