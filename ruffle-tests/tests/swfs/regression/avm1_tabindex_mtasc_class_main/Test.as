class Test { static function main(mc) { var r:Object = _root; r.tabIndex="s"; trace(r.tabIndex); r.tabIndex=5; trace(r.tabIndex); r.tabIndex="t"; trace(r.tabIndex);
 _root.createEmptyMovieClip("m",2); var m:Object = r.m; m.tabIndex=0; m.tabIndex="t"; trace(m.tabIndex);
 _root.createEmptyMovieClip("n",3); var n:Object = r.n; n.tabIndex=undefined; n.tabIndex="u"; trace(n.tabIndex); n.tabIndex=7; trace(n.tabIndex); } }
