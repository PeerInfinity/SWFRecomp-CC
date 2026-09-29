#!/bin/bash
# Launch a fan-out wave-2 worker as a Claude Code CLOUD session, in the
# "SWFRecomp fan-out" environment (setup script installs apt deps, Pillow and
# the prebuilt Dawn at /root/CC/dawn-install). See
# SWFRecompDocs/plans/graphics-fanout-playbook.md §5a for the whole procedure.
#
# usage: scripts/fanout_cloud_worker.sh <task-slug> <prompt-file> [logfile]
#   <task-slug>   names the delivery branch: fanout/<task-slug>
#   <prompt-file> the complete brief (the launch prompt is the ONLY input
#                 channel a cloud worker reliably receives)
#
# Prints the created session id/URL. Then watch for delivery with:
#   until git ls-remote --exit-code origin refs/heads/fanout/<task-slug> >/dev/null; do sleep 120; done
# (run it with run_in_background) and read progress with
#   RemoteTrigger get_run_log session_id=<session_…>
set -euo pipefail
SLUG=${1:?task slug}; PROMPT=${2:?prompt file}
LOG=${3:-/tmp/fanout-cloud-$SLUG.log}
ENV_ID=${SWFRECOMP_CLOUD_ENV:-env_01QSs9FrDsLyis2RzQXg1UrW}   # "SWFRecomp fan-out"
[ -s "$PROMPT" ] || { echo "empty prompt file: $PROMPT" >&2; exit 2; }
grep -q "fanout/$SLUG" "$PROMPT" || { echo "prompt must name its delivery branch fanout/$SLUG" >&2; exit 2; }
# The cloud clones GitHub: everything the prompt references must be PUSHED.
git fetch -q origin
if [ "$(git rev-parse HEAD)" != "$(git rev-parse origin/master)" ]; then
  echo "warning: local HEAD != origin/master — unpushed commits are invisible to the cloud worker" >&2
fi
TMP=$(mktemp)
cat > "$TMP" <<INNER
#!/bin/bash
exec claude --settings '{"remote":{"defaultEnvironmentId":"$ENV_ID"}}' --cloud "\$(cat '$PROMPT')"
INNER
chmod +x "$TMP"
# --cloud needs a pty; `script` provides one. Returns in ~10 s.
script -qfec "$TMP" "$LOG" < /dev/null >/dev/null
rm -f "$TMP"
grep -aoE 'Created cloud session: .*|https://claude.ai/code/session_[A-Za-z0-9]+' "$LOG" | sort -u
