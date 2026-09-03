package {
    import flash.display.Sprite;
    // Frame-2 class for child.swf: its only job is to give the child SWF a
    // SECOND frame, so the child root's `totalFrames` is 2 and therefore reads
    // its timeline row (keyed by char id) rather than the "no timeline" default
    // of 1. See README.md.
    public class Second extends Sprite {}
}
