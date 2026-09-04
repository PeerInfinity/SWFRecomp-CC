package probe {
	// Declares a member with the SAME NAME as Base's private one. They are
	// genuinely different slots; only the owner argument tells them apart.
	public class Sub extends Base {
		protected var shadowed:String = "sub-protected";
		public function readOwnShadowed():String { return shadowed; }
	}
}
