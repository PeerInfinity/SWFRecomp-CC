package probe {
	// The dynamic control: an ordinary name read on a DYNAMIC class returns
	// undefined instead of throwing, so both shapes of "ordinary access
	// cannot see it" are pinned.
	public dynamic class Dyn {
		private var hidden:String = "dyn-private";
	}
}
