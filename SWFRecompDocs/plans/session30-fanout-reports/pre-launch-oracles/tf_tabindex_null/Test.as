class Test {
  static function main(mc) {
    _root.createTextField("t", 1, 0, 0, 100, 20);
    var t = _root.t;
    trace("init " + t.tabIndex + " " + typeof(t.tabIndex));
    t.tabIndex = 5; trace("num " + t.tabIndex + " " + typeof(t.tabIndex));
    t.tabIndex = null; trace("null " + t.tabIndex + " " + typeof(t.tabIndex));
    t.tabIndex = "7"; trace("str " + t.tabIndex + " " + typeof(t.tabIndex));
    t.tabIndex = undefined; trace("undef " + t.tabIndex + " " + typeof(t.tabIndex));
    t.tabIndex = 3; t.tabIndex = "abc"; trace("nanstr " + t.tabIndex + " " + typeof(t.tabIndex));
    t.tabIndex = -2147483648; trace("min " + t.tabIndex);
    t.tabIndex = 3; t.tabIndex = -1; trace("neg " + t.tabIndex);
    t.tabIndex = 3.7; trace("frac " + t.tabIndex);
    t.tabIndex = true; trace("bool " + t.tabIndex + " " + typeof(t.tabIndex));
    t.tabIndex = 4; delete t.tabIndex; trace("del " + t.tabIndex);
    var o = {}; for (var k in t) { if (k == "tabIndex") trace("enum tabIndex"); }
    trace("done");
  }
}
