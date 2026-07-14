package {
    import flash.display.Sprite;
    import flash.utils.ByteArray;
    // A Flex [Embed] octet-stream asset -> a ByteArrayAsset subclass bound to a
    // DefineBinaryData char via SymbolClass. `new Payload()` must be populated.
    public class Test extends Sprite {
        [Embed(source="payload.bin", mimeType="application/octet-stream")]
        private static var Payload:Class;
        public function Test() {
            var ba:ByteArray = new Payload();
            trace("length=" + ba.length);
            trace("text=" + ba.readUTFBytes(ba.length));
        }
    }
}
