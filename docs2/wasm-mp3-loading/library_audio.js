// Emscripten library that provides js_play_pcm() and js_log() to demo.c.
// Linked into the build via --js-library library_audio.js.

mergeInto(LibraryManager.library, {
    js_log: function(ptr, n) {
        var msg = UTF8ToString(ptr, n);
        var box = document.getElementById('log');
        if (box) {
            box.textContent += msg + '\n';
            box.scrollTop = box.scrollHeight;
        }
        console.log('[demo]', msg);
    },

    js_play_pcm: function(labelPtr, labelLen, samplesPtr, nSamples, channels, hz) {
        var label = UTF8ToString(labelPtr, labelLen);

        // AudioContext lazy-create on first playback (user has clicked a
        // button by now, so autoplay policy is satisfied).
        if (!window._demoCtx) {
            var AC = window.AudioContext || window.webkitAudioContext;
            window._demoCtx = new AC();
        }
        var ctx = window._demoCtx;
        if (ctx.state === 'suspended') ctx.resume();

        // Track active sources so Stop can halt them. Lazy-init on first play.
        if (!window._demoActive) {
            window._demoActive = [];
            var stopBtn = document.getElementById('btn-stop');
            window._demoUpdateStopBtn = function() {
                if (stopBtn) stopBtn.disabled = window._demoActive.length === 0;
            };
            window._demoStopAll = function() {
                window._demoActive.slice().forEach(function(s) {
                    try { s.stop(); } catch (_) {}
                });
                window._demoActive.length = 0;
                window._demoUpdateStopBtn();
                console.log('[demo] stopped all sources');
            };
        }

        // Copy interleaved float PCM out of the WASM heap and de-interleave
        // into an AudioBuffer.
        var interleaved = HEAPF32.subarray(samplesPtr >> 2,
                                           (samplesPtr >> 2) + nSamples * channels);
        var buffer = ctx.createBuffer(channels, nSamples, hz);
        for (var ch = 0; ch < channels; ch++) {
            var out = buffer.getChannelData(ch);
            for (var i = 0; i < nSamples; i++) out[i] = interleaved[i * channels + ch];
        }

        var loopToggle = document.getElementById('loop-toggle');
        var loop = !!(loopToggle && loopToggle.checked);

        var src = ctx.createBufferSource();
        src.buffer = buffer;
        src.loop = loop;
        src.connect(ctx.destination);

        window._demoActive.push(src);
        window._demoUpdateStopBtn();
        src.onended = function() {
            var i = window._demoActive.indexOf(src);
            if (i >= 0) window._demoActive.splice(i, 1);
            window._demoUpdateStopBtn();
        };

        src.start();
        console.log('[demo] playing', label, '-', nSamples, 'samples',
                    channels, 'ch @', hz, 'Hz', loop ? '(looping)' : '');
    }
});
