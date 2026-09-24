# Agent Instructions — Unreal Shared Anchors Sample

Unreal demo of the Spatial Anchors system on Meta Quest — creating, persisting, loading, hiding, erasing, and sharing anchors across users in a session, with Unreal's SaveGame system used to persist anchor UUIDs to app storage.

## Source-of-truth files (read these first, do not duplicate their contents in this file)

For setup, build steps, SDK versions, and project layout, read:

- `README.md` — official setup, dashboard prerequisites, and run instructions
- `SharedAnchorsSample.uproject` — Unreal engine association and enabled plugins (`OculusXR`, `OculusPlatform`)
- `Config/DefaultEngine.ini` — anchor-sharing configuration (`[OnlineSubsystemOculus] > MobileAppId`, `[/Script/AndroidRuntimeSettings.AndroidRuntimeSettings] > PackageName`)
- `Source/SharedAnchorsSample/` — C++ module sources and `.Build.cs`
- `LICENSE` — license terms (Meta License for SDK material; MIT for clearly-marked docs)

## Quest / Horizon-specific notes

- Git LFS is required; run `git lfs install` before cloning.
- **Dashboard prerequisites are non-optional** for anchor sharing to work end-to-end: create a Meta Quest developer org + app, add User ID and User Profile in Data Use Checkup, configure upload via the Unreal Platform Tool, and add test users to the release channel. Without these, anchor sharing will silently fail.
- `Config/DefaultEngine.ini` ships with placeholder values for `MobileAppId` and `PackageName` — both must be replaced with your own values before packaging, and the packaged build must be uploaded under that same App ID for entitlement checks to succeed.
- This sample uses the **older user-based** anchor sharing flow. Meta XR has since moved to group-based sharing (v71+). For new sharing code, prefer the group-based API unless deliberately matching this sample's existing pattern.
- The only interaction surface is the right-controller menu (`BP_Menu_Main` / `BP_Menu_Anchor` / `BP_MenuItem`); there is no UMG screen UI.
- "Erase Anchor" on a cloud-saved anchor removes it from the scene but does **not** delete it from cloud storage.

# Meta Quest tooling

This is a Meta Quest / Horizon OS sample. The bespoke intro above is the source of truth for what this project is and how it's built — use it (and the files it points at) instead of restating facts from memory.

When the user asks anything about Quest device behavior, build / deploy / debug / capture flows, on-device performance, or Horizon OS APIs, reach for these tools instead of generic Unreal answers:

- **`hzdb`** — Quest-aware ADB wrapper (device list, install / launch / stop, logs, screenshots, Perfetto traces, on-device docs search). Already wired up as an MCP server via `.mcp.json`, `.vscode/mcp.json`, and `.cursor/mcp.json`. Also runnable directly: `npx -y @meta-quest/hzdb <subcommand>`.
- **Meta Quest Agentic Tools** — the full skill set, including Unreal-specific skills: <https://github.com/meta-quest/agentic-tools>. Install per your client (Claude Code: `/plugin install meta-vr@meta-quest`; Gemini CLI: `gemini extensions install https://github.com/meta-quest/agentic-tools`; Cursor / VS Code: install the **Meta Horizon** extension from the Marketplace).

A few behavior expectations:

- **Read this repo's files first.** Before answering anything project-specific, read `README.md` and whichever source-of-truth files the intro above points at. Don't restate their contents in chat — quote or link instead.
- **Use `hzdb` for device-side work.** Anything that touches an attached Quest (install, launch, logs, screenshot, capture, manifest inspection) goes through `hzdb`, not raw `adb`.
- **Check live Horizon OS docs before answering API questions.** `hzdb docs search "..."` queries the live docs; training data on Horizon OS APIs goes stale fast.
- **Don't fabricate SDK / engine versions.** If a version isn't visible in this repo's files, say so rather than guessing.
