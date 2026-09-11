class Parent {
    static var mcl:MovieClipLoader;
    static var lis:Object;
    static var t:Number = 0;
    static function main(root:MovieClip) {
        var h:MovieClip = root.createEmptyMovieClip("h", 1);
        mcl = new MovieClipLoader();
        lis = new Object();
        lis.onLoadStart = function(tgt) { trace("onLoadStart"); };
        lis.onLoadProgress = function(tgt, bl, bt) { trace("onLoadProgress"); };
        lis.onLoadComplete = function(tgt) { trace("onLoadComplete"); };
        lis.onLoadInit = function(tgt) { trace("onLoadInit cf=" + tgt._currentframe); };
        mcl.addListener(lis);
        root.onEnterFrame = function() {
            Parent.t++;
            trace("t" + Parent.t + " h.cf=" + root.h._currentframe);
            if (Parent.t >= 6) { delete root.onEnterFrame; }
        };
        trace("loadClip");
        mcl.loadClip("child.swf", h);
    }
}
