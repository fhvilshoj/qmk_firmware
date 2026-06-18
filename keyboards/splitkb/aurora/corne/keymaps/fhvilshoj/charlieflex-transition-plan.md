# Corne → Charlieflex Transition Plan

A staged plan to retrain my muscle memory onto a ~32-key mental model **on my
existing Corne**, so that when the Charlieflex is built I can type on it from
day one. The trick: keep all the Corne's physical keys, but progressively
neutralize the keys that won't exist on the Charlieflex, one capability at a
time, so my hands reorganize around the smaller set before the new board arrives.

---

## Context

|                           |                                                                                                                                                                                               |
| ------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Current board**         | Aurora Corne — 42 keys (`LAYOUT_split_3x6_3`), wired, QMK                                                                                                                                     |
| **Target commuter board** | Charlieflex (`ctranstrum/chuck`) — ~31–32 keys, unibody, wireless, ZMK, Choc hotswap                                                                                                          |
| **Why**                   | Two-piece split is unstable on a train/plane tray table; want a stable one-piece board with built-in splay for slightly wider elbows in cramped spaces. Corne stays for wide-spread desk use. |
| **Firmware shift**        | QMK C (`keymap.c`) → **ZMK devicetree** (`.keymap`). Logic ports cleanly; syntax does not. ZMK Studio allows live remap without recompiling.                                                  |
| **Endgame**               | Once the model is locked, retire the Corne for a 34-key wireless Choc split (wide daily driver) + Charlieflex (commuter), both flashed from **one ZMK keymap**.                               |

### What the Charlieflex actually constrains the target layout to

- **5 columns per hand** — no outer pinky column.
- **Inner index column cut to 2 keys** (no index stretch).
- **Pinky lowered**, top pinky key traded for a ring-finger key.
- **~3 thumbs total** (my build: 2 left / 1 right).
- Therefore: **symmetric home-row mods** + **combos/thumbs** must absorb everything the lost keys used to do.

### What changes vs. my current `keymap.c` (summary)

1. **Outer pinky column disappears** (6 keys). Standalone `CTL`/`SHFT`/`RALT` there are already redundant with my mods; the real casualties are `TAB`, `BSPC`, `'`.
2. **Thumbs 6 → 3**. Fold layer-holds into the keys they pair with via layer-taps.
3. **Home-row mods become load-bearing and must be symmetric** — right home row currently has _no_ mods. This is the single biggest motor change.
4. **Inner index column loses one key per hand** (`B` / `N` relocate).
5. **More reliance on combos** to recover `TAB`, `'`, `B`, `N`, etc. (`jk → ESC` combo already exists and stays.)

### Whats this plan can NOT rehearse

The Charlieflex's physical **splay and lowered-pinky stagger**. The Corne's columns stay put, so the _logical_ model will be identical but the fingertips will feel the geometry on day one. That's a comfort adjustment, not a re-learning.

---

## Operating principles

- **One change per ~1–2 weeks.** Don't stack. Each step feels awkward for a few days → normal → _then_ advance.
- **Hardest first, while crutches still exist.** Symmetric home-row mods go first while every other key is still where I expect it.
- **Never get stuck.** Each step adds the new home _before_ removing the old key, so I can always fall back by reverting one line.

---

## Step 1 — Symmetric home-row mods; kill the top-row mods

**Goal:** both hands modify independently (required once the outer mod column is gone).

- [x] Mirror left-hand GASC onto the right home row (same finger → same mod):
    ```
    J = RCTL_T(KC_J)   K = RSFT_T(KC_K)   L = RALT_T(KC_L)   ; = RGUI_T(KC_SCLN)
    ```
- [x] Revert top-row mod-taps to plain letters: `RCTL_T(KC_W) → KC_W`, `RALT_T(KC_E) → KC_E`.
- [x] **Drop Shift-on-Space thumb** (`MT(MOD_LSFT, KC_SPC) → KC_SPC`): pulled
      forward from Step 4 so shifting moves to the new middle-finger home-row mod
      immediately, while the motor change is already being learned.
- [ ] Run for the **longest** stretch of any step — this is the deepest motor change.

_Safe to do first: it's additive (gain right-hand mods, lose nothing essential)._

---

## Step 2 — Pre-place TAB, BSPC, and `'` (keep old keys as a crutch)

**Goal:** give the three genuine casualties their Charlieflex homes while the outer column still works.

- [x] **BSPC → left outer thumb** (was plain `LGUI`; Gui is now covered by `A` and `;` home-row mods).
- [x] **TAB → left-hand combo** — now `S`+`D` (`COMB(SD_TAB, KC_TAB, LALT_T(KC_S), LSFT_T(KC_D))`); moved off `Q`+`W` because the home-row pair is comfier and `Q`+`W` freed up for **Caps Word** (`COMB(QW_CAPS, CW_TOGG, KC_Q, KC_W)`, needs `CAPS_WORD_ENABLE`) — handy since home-row-mod Shift makes long runs of capitals awkward; auto-cancels at word end and keeps `_`/digits (ideal for `SCREAMING_SNAKE`). `S`+`D` chosen over the `A`+`S` mirror of `'` because `as/ask/last/fast` would misfire as TAB; `sd` is a near-nonexistent bigram.
- [x] **`'` → combo** `L`+`;` (`COMB(LSCLN_QUOT, KC_QUOT, RALT_T(KC_L), RGUI_T(KC_SCLN))` — mod-tap keycodes per the Step 2 caveat).
- [x] **Disabled the base-layer `TAB` and `'` keys early** (`XXXXXXX`) — pulled forward from Step 3 to force the combos immediately. Outer `CTL`/`SFT`/`RALT`/`BSPC` stay as crutches; only TAB and `'` go dark for now.
- [ ] Consciously start reaching for the new homes. Outer keys still work as backup.

> ⚠️ **Combos must use the home-row-mod keycode, not the bare letter.** QMK matches
> combos against the _exact_ keycode sitting in the keymap at each position. Since
> Step 1, `j k l ;` are mod-taps, so a combo over them needs the wrapped form —
> e.g. `RALT_T(KC_L), RGUI_T(KC_SCLN)` for `l+;`, **not** `KC_L, KC_SCLN`. Using the
> bare letter compiles fine but the combo silently never fires. (This is exactly
> what broke `jk → ESC` after Step 1.) `q+w` is safe as plain `KC_Q, KC_W` — those
> aren't mods. Rule of thumb: if either key in a combo is a home-row mod, wrap it.

---

## Step 3 — Disable the entire outer pinky column

**Goal:** force the hands into the 5-column world.

- [x] **No-op the outer pinky column on every layer.** Done across BL / NUM / CH / FN —
      both hands, all rows are `XXXXXXX`. The board is now logically **5 columns per hand**.
      Nothing irreplaceable was lost; each casualty had a home first:
    - `TAB` → `s+d` combo · `'` → `l+;` combo · `RALT`(🌐) → left thumb (see below)
    - `_` / `` ` `` (CH) → `l;` / `./` combos — old CH outer positions now disabled
    - `LCTL` / `LSFT` (all layers) → redundant with home-row mods, just removed
    - `BSPC` (right-top, all layers) → removed; lives on the left thumb now
    - `F1` / `F12` / `QK_BOOT` (FN) → relocated inward (`F1`→under `F2`,
      `F12`→under `F11`, `QK_BOOT`→one right) before clearing the column
- [x] Moment-of-truth step survived — landed quickly because Steps 1–2 pre-placed the homes.

### 🌐 Globe / `fn` — resolved: **mod-tap on the left thumb**

The bottom-right `RALT` was my macOS Globe key (Right-Alt → 🌐 remapped in _Keyboard →
Modifier Keys_; QMK can't emit Apple's Globe HID usage, so it just sends `RALT`).
Disabling the outer column kills that corner, so Globe needs a holdable home that
chords with the NUM-layer arrows (window tiling = 🌐 + Ctrl + arrow).

- [x] **Left outer thumb → `RALT_T(KC_BSPC)`** (tap = `⌫` BSPC, hold = 🌐 Globe).
- [x] **Disable the old `RALT` corner** (`XXXXXXX`).
- Tiling chord splits across both hands, no collisions: 🌐(left thumb) +
  Ctrl(`f`, a plain mod on the NUM layer) + NUM(right thumb) + arrow(right hand).
  Also covers `fn`+arrows (Home/End/PgUp/Dn), `fn`+Delete, emoji, etc.
- **Tradeoff:** Backspace is now **tap-only** (the hold is Globe) — no hold-to-repeat.
  Revisit with a layer'd delete-word if that bites.

---

## Step 4 — Collapse six thumbs down to three

**Goal:** match the Charlieflex thumb count; fold layer-holds into the keys they pair with.

Current cluster: `GUI · MO(CH) · Ctrl/Enter` ‖ `Shift/Space · MO(NUM) · Hyper/Alt`

- [ ] Re-map to layer-taps + tri-layer (**Globe ↔ CH swapped** — see note):
    ```
    left  outer thumb:  LT(CH, KC_BSPC)       // CH symbols on hold, BSPC on tap   ← CH took the Globe key
    left  inner thumb:  MT(MOD_RALT, KC_ENT)  // 🌐 Globe on hold, Enter on tap     ← Globe took the CH/Enter key
    right thumb:        LT(NUM, KC_SPC)        // numbers on hold, Space on tap
    FN layer:           tri-layer — hold CH + NUM together to reach FN
    ```
- [ ] Disable the two now-unused thumb positions (`XXXXXXX`).

**Globe ↔ CH swap (vs. the original plan).** CH is years-deep muscle memory, so it
takes the **outer** thumb (today's Globe key) and Globe moves to the **inner** thumb
(the Enter key). Only the _holds_ swap — the **taps stay put** (BSPC on outer, Enter
on inner), so it's the smallest possible migration. Nothing prohibits it:

- Globe is still a held mod → window tiling is unchanged: 🌐(inner thumb) + Ctrl(`f`)
    - NUM(right thumb) + arrow — thumb+index, no collision.
- The FN tri-layer only needs CH+NUM held; which thumb each sits on doesn't matter.
- Globe-on-Enter-hold is the same tap-hold shape as today's Ctrl-on-Enter, and an
  accidental Globe+key is _less_ destructive than the accidental Ctrl+key it replaces.

_Gut-check: CH is more frequent than Globe and the outer thumb is a slightly longer
reach than the inner — so the swap puts the busier key on the harder thumb. If the CH
habit outweighs that (likely, after years), keep it; flipping back is a two-line change._

_Shift-on-Space and Ctrl-on-Enter holds being dropped are already covered by the new symmetric home-row mods._

### `Hyper` — resolved: **one-shot Apps layer**

Hyper is used aggressively for app switching and must stay ergonomic. Don't hold a
four-mod chord — tap a one-shot into a layer where each key sends the full Hyper combo.
With only 3 thumbs (all used) and the outer column gone, there's no spare key, so the
one-shot lives on a **combo** — costing zero keys.

- [ ] Trigger the Apps layer as a **one-shot on a combo** (tap combo → tap app → fires once):
    ```c
    // QMK: OSL(APPS) on a combo (define in keymap_combo.h / combo source)
    // ZMK: &sl APPS on a combo
    ```
    Default combo: a comfortable, low-misfire pair of **non-mod-tap** keys (e.g. `C`+`V`).
    Avoid "both left thumbs" — both are tap-hold keys now (CH-tap-BSPC and Globe-tap-Enter),
    so chording them is fiddlier than two plain keys. Combo position is easy to move — tune later.
- [ ] Add an `APPS` layer. Put **most-used apps on home row** as discrete Hyper combos;
      fill the rest so any key = `Hyper`+itself (keeps ad-hoc Hyper available):
    ```c
    // QMK: HYPR(kc) = Ctrl+Alt+Shift+Gui + kc
    [APPS] = LAYOUT_split_3x6_3(
        _______, HYPR(KC_Q), HYPR(KC_W), HYPR(KC_E), HYPR(KC_R), HYPR(KC_T), /* ... */
        _______, HYPR(KC_A), HYPR(KC_S), HYPR(KC_D), HYPR(KC_F), HYPR(KC_G), /* ... */
        /* fill remaining keys with HYPR(KC_x) */
    )
    ```
- [ ] **ZMK equivalent** (for Charlieflex / future splits, one shared model):
    ```
    #define HY(key) LG(LC(LA(LS(key))))   // wrap any keycode in Hyper
    // one-shot trigger (combo):  &sl APPS
    // layer keys:  &kp HY(T)   &kp HY(S)   ...
    ```
- [ ] Fill in actual app → key map: \***\*\*\*\*\*\*\***\_\_\_\***\*\*\*\*\*\*\***

_One-shot = tap, tap app, done — no hold, ideal for frequent single fires. For a run of
several Hyper combos, tap the combo again each time (or add a hold/toggle variant later).
Benefits: no four-mod chord ever pressed; app positions remappable independent of the
letter underneath; identical across Corne, Charlieflex, and future splits._

---

## Step 5 — Trim the inner index column → parity

**Goal:** match the Charlieflex anti-stretch geometry.

- [ ] Relocate `B` and `N` (bottom-inner index) to a combo or layer.
- [ ] Disable those two positions on the Corne (`XXXXXXX`).

**End state:** the Corne is _logically_ a ~32-key board — 5 columns, inner index of 2, three thumbs, symmetric home-row mods, combos for TAB/`'`/ESC/B/N, BSPC/SPC/ENT/layers on thumbs. **This is the Charlieflex mental model**, on hardware I've used the whole time.

### Target layout — the 32-key mental model (base layer)

What the hands actually use once all five steps land. Only live keys are drawn;
the Corne's outer pinky column, the two inner-index bottoms, and three thumbs are
gone. Home-row mods are symmetric (same finger → same mod on both hands).

```
╭───┬───┬───┬───┬───╮             ╭───┬───┬───┬───┬───╮
│ q │ w │ e │ r │ t │             │ y │ u │ i │ o │ p │
├───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┤
│ a │ s │ d │ f │ g │             │ h │ j │ k │ l │ ; │
│ ⌘ │ ⌥ │ ⇧ │ ⌃ │   │             │   │ ⌃ │ ⇧ │ ⌥ │ ⌘ │
├───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┤
│ z │ x │ c │ v │   │             │   │ m │ , │ . │ / │
╰───┴───┴───┴───┴───╯             ╰───┴───┴───┴───┴───╯
          ╭──────────┬─────────╮ ╭────────╮
          │ ⌫ · CH   │ ⏎ · 🌐  │ │ ␣ · NUM│
          ╰──────────┴─────────╯ ╰────────╯
          (2 left thumbs)         (1 right thumb)
```

- **Home-row mods** (hold): pinky=⌘ · ring=⌥ · middle=⇧ · index=⌃, both hands.
- **Thumbs** (tap · hold):
    - left outer → `⌫` BSPC (tap) · **CH** symbols layer (hold) — tap-only BSPC, no hold-repeat
    - left inner → `⏎` Enter (tap) · **🌐 Globe / RALT** (hold)
    - right → `␣` Space (tap) · **NUM** numbers/arrows layer (hold)
    - hold **CH + NUM together** → **FN** layer (tri-layer)
- **Window tiling** = 🌐(left inner thumb) + Ctrl(`f`) + NUM(right thumb) + arrow. macOS
  remaps Right-Alt → 🌐 in _Keyboard → Modifier Keys_; firmware just sends `RALT`.
- **Combos** recover everything the lost keys did:

    | Combo                | Sends                     | Recovers                                              |
    | -------------------- | ------------------------- | ----------------------------------------------------- |
    | `s`+`d`              | `⇥` TAB                   | killed outer column                                   |
    | `l`+`;`              | `'` quote                 | killed outer column                                   |
    | `j`+`k`              | `ESC`                     | (already exists)                                      |
    | `q`+`w`              | `⇪` Caps Word             | (new convenience — HRM Shift makes long caps awkward) |
    | `l`+`;` _(CH layer)_ | `_` underscore            | CH outer column                                       |
    | `.`+`/` _(CH layer)_ | `` ` `` backtick          | CH outer column                                       |
    | _tbd_                | `b`                       | trimmed inner-index                                   |
    | _tbd_                | `n`                       | trimmed inner-index                                   |
    | _tbd_                | one-shot **APPS** (Hyper) | killed Hyper/Alt thumb                                |

> The one thing this picture can't show is _feel_: on the Charlieflex the pinky
> column sits lower and the whole board splays outward. The logical model above is
> identical — only the fingertips will notice the geometry on day one.

---

## Progress tracker

| Step | Change                            | Started    | "Feels normal"         | Notes                                                                                                                                                                                                                                              |
| ---- | --------------------------------- | ---------- | ---------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1    | Symmetric HRM + drop top-row mods | 2026-06-15 | Wednesday, 2026-Jun-17 | Right home row now CTL/SFT/ALT/GUI on j/k/l/;; w/e top-row mods reverted to plain; Shift-on-Space thumb dropped (pulled fwd from Step 4)                                                                                                           |
| 2    | Pre-place TAB / BSPC / `'`        | 2026-06-15 |                        | BSPC→left outer thumb; TAB→combo (now on `sd`); `'`→`l;` combo. Base-layer TAB+`'` disabled early                                                                                                                                                  |
| 3    | Disable outer pinky column        | 2026-06-16 |                        | **Done 2026-06-17.** Outer column fully `XXXXXXX` on all 4 layers → logical 5-col board. 🌐 Globe→left thumb (`RALT_T(KC_BSPC)`, tap-only BSPC); F1/F12/QK*BOOT relocated inward on FN; `*`/`` ` ``→CH combos; TAB moved `qw`→`sd`; `qw`→Caps Word |
| 4    | Six thumbs → three                |            |                        | Hyper → one-shot Apps layer (`OSL(APPS)` on a combo)                                                                                                                                                                                               |
| 5    | Trim inner index column           |            |                        |                                                                                                                                                                                                                                                    |

---

## Endgame: two small splits to companion the Charlieflex

Once the 32-key model is locked, the 42-key Corne is carrying ~10 keys my hands no
longer use — natural to retire it for a **34-key wireless Choc split** as the _wide_
daily driver, with the Charlieflex as the commuter.

- Candidate wide boards: **Aurora Sweep, Cantor (Remix), Chocofi, Urchin** (all 34-key, wireless-capable, Choc).
- Flash **all boards from one ZMK keymap.** A 34-key split has two _spare_ keys vs. the Charlieflex's 32 — leave them as duplicates/conveniences. (The inverse of the "Miryoku wastes keys on a Corne" problem, and trivial.)
- Result: one mental model across three boards — wide split at the desk, Charlieflex on the train, original Corne as backup/sale.

---

## Reference configs & reading

- **`JeffDess/zmk-config`** — runs a Corne (36) and Urchin (34) off **one shared config**; proof that cross-board muscle memory works. Best "use both" model.
- **`nickfaraco/zmk-config`** — Chocofi 34/36, based on **urob's** keymap; shows symbols/parens recovered as combos.
- **`ferrance/dizave42`** — honest "why I stopped at 42 / Miryoku tradeoffs" account.
- **Miryoku** — canonical 36-key reference layout.
- **urob's ZMK config** — the "timeless home-row mods" everyone copies.
- **`ctranstrum/chuck` (`zmk` branch)** — Charlieflex firmware + the author's **"Twentyone Chuck Street"** default layout. Read `config/` / `boards/shields/`. Supports **ZMK Studio** (live remap).

---

## Next artifacts to generate (optional)

- [ ] Five drop-in `keymap.c` revisions (one per step), ready to flash in sequence.
- [ ] Matching ZMK `.keymap` for the end state, so the eventual Charlieflex/split flash is copy-paste.
