class Test {
    static function main() {
        var p:MovieClip = _root.createEmptyMovieClip("parentClip", 1);
        var c:MovieClip = p.createEmptyMovieClip("childClip", 1);
        c.duplicateMovieClip("dupChild", 2);
        var d:MovieClip = p.dupChild;
        trace("typeof p.dupChild=" + typeof(p.dupChild));
        trace("d._target=" + d._target);
        trace("d._parent._name=[" + d._parent._name + "]");
        trace("d._parent==parentClip:" + (d._parent == p));
        trace("typeof _root.dupChild=" + typeof(_root.dupChild));
    }
}
