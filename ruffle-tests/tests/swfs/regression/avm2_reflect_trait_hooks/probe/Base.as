package probe {
	// A stand-in for the kind of class an injected recorder has to read:
	// compiled, source-less at observation time, and with everything
	// interesting declared private or protected.
	public class Base {
		private var shadowed:String = "base-private";
		protected var prot:int = 7;
		protected static var protStat:String = "base-prot-static";
		protected static const FROZEN:int = 5;
		public var pub:String = "public-value";

		private var _acc:Number = 1.5;
		protected function get accessor():Number { return _acc * 2; }
		protected function set accessor(v:Number):void { _acc = v; }

		protected function secretMethod():String { return "method"; }

		// Reads BASE's own private slot even on a Sub receiver (private
		// members are not virtual) — the value the owner argument must be
		// able to reach.
		public function readShadowed():String { return shadowed; }
	}
}
