
## Maps

This keymap is mid-transition to a ~32-key Charlieflex model (see
`charlieflex-transition-plan.md`). **The outer pinky column is disabled
(`XXXXXXX`) on every layer**, so the board is logically **5 columns per hand**.
The diagrams below show only live keys. Thumbs are still 6 (the collapse to 3 is
Step 4 — not done yet).

Home-row mods are **symmetric** — same finger sends the same mod on both hands:
pinky = ⌘ Cmd, ring = ⌥ Opt, middle = ⇧ Shift, index = ⌃ Ctrl.

### COMBOS

| Combo | Output | Notes |
|-------|--------|-------|
| `j`+`k` | `ESC` | |
| `s`+`d` | `⇥` TAB | home-row, base layer |
| `l`+`;` | `'` quote | base layer |
| `q`+`w` | `⇪` Caps Word | auto-cancels at end of word; keeps `_`/digits |
| `l`+`;` | `_` underscore | **CH layer only** |
| `.`+`/` | `` ` `` backtick | **CH layer only** |

### THUMBS (base layer)

| Thumb | Tap | Hold |
|-------|-----|------|
| left outer | `⌫` Backspace | 🌐 Globe (`RALT`) |
| left mid | — | `CH` symbol layer |
| left inner | `⏎` Enter | ⌃ Ctrl |
| right inner | `␣` Space | — |
| right mid | — | `NUM` number/arrow layer |
| right outer | `⌥` Alt | ✦ Hyper (Ctrl+Alt+Shift+Gui) |

🌐 Globe: macOS remaps Right-Alt → 🌐 in *Keyboard → Modifier Keys*, so the
firmware just sends `RALT`. Window tiling = 🌐(left thumb) + Ctrl(`f`, also a mod
on NUM) + NUM(right thumb) + arrow. Backspace is **tap-only** (the hold is Globe).

### BASE LAYER

```
╭───┬───┬───┬───┬───╮     ╭───┬───┬───┬───┬───╮
│ q │ w │ e │ r │ t │     │ y │ u │ i │ o │ p │
├───┼───┼───┼───┼───┤     ├───┼───┼───┼───┼───┤
│ a │ s │ d │ f │ g │     │ h │ j │ k │ l │ ; │
│ ⌘ │ ⌥ │ ⇧ │ ⌃ │   │     │   │ ⌃ │ ⇧ │ ⌥ │ ⌘ │
├───┼───┼───┼───┼───┤     ├───┼───┼───┼───┼───┤
│ z │ x │ c │ v │ b │     │ n │ m │ , │ . │ / │
╰───┴───┴───┴───┴───╯     ╰───┴───┴───┴───┴───╯
   ╭──────┬──────┬──────╮   ╭──────┬──────┬──────╮
   │ 🌐⌫  │  CH  │  ⌃⏎  │   │  ␣   │ NUM  │ ⌥Hyp │
   ╰──────┴──────┴──────╯   ╰──────┴──────┴──────╯
```

### NUMBERS AND ARROWS (NUM)

```
╭───┬───┬───┬───┬───╮     ╭───┬───┬───┬───┬───╮
│ 1 │ 2 │ 3 │ 4 │ 5 │     │ 6 │ 7 │ 8 │ 9 │ 0 │
├───┼───┼───┼───┼───┤     ├───┼───┼───┼───┼───┤
│ ⌘ │ ⌥ │ ⇧ │ ⌃ │   │     │ ← │ ↓ │ ↑ │ → │   │
├───┼───┼───┼───┼───┤     ├───┼───┼───┼───┼───┤
│   │   │   │   │   │     │   │   │   │   │   │
╰───┴───┴───┴───┴───╯     ╰───┴───┴───┴───┴───╯
   ╭──────┬──────┬──────╮   ╭──────┬──────┬──────╮
   │  ⌘   │  FN  │  ⏎   │   │  ␣   │(NUM) │  ⌥   │
   ╰──────┴──────┴──────╯   ╰──────┴──────┴──────╯
```

Left home row keeps the GASC mods (so Ctrl on `f` is available for 🌐+Ctrl+arrow
window tiling). `FN` layer = hold the left-mid thumb here, or NUM+CH together.

### SPECIAL CHARACTERS (CH)

```
╭───┬───┬───┬───┬───╮     ╭───┬───┬───┬───┬───╮
│ ! │ @ │ # │ $ │ % │     │ & │ * │ ( │ ) │ ^ │
├───┼───┼───┼───┼───┤     ├───┼───┼───┼───┼───┤
│   │   │   │   │   │     │ | │ = │ [ │ ] │ - │
├───┼───┼───┼───┼───┤     ├───┼───┼───┼───┼───┤
│   │   │   │   │   │     │ ~ │ + │ { │ } │ \ │
╰───┴───┴───┴───┴───╯     ╰───┴───┴───┴───┴───╯
   ╭──────┬──────┬──────╮   ╭──────┬──────┬──────╮
   │  ⌘   │ (CH) │  ⏎   │   │  ␣   │  FN  │  ⌥   │
   ╰──────┴──────┴──────╯   ╰──────┴──────┴──────╯
```

`_` and `` ` `` live on this layer's combos (`l;` and `./`) — they used to sit on
the now-removed outer column.

### FUNCTION KEYS AND MOUSE (FN)

Reached by holding NUM + CH together (or the FN thumb from NUM/CH).

```
╭────┬────┬────┬────┬────╮     ╭────┬────┬────┬─────┬─────╮
│ F2 │ F3 │ F4 │ F5 │ F6 │     │ F7 │ F8 │ F9 │ F10 │ F11 │
├────┼────┼────┼────┼────┤     ├────┼────┼────┼─────┼─────┤
│ F1 │ Vo │ V- │ V+ │    │     │ ←  │ ↓  │ ↑  │  →  │ F12 │
├────┼────┼────┼────┼────┤     ├────┼────┼────┼─────┼─────┤
│ BT │    │ B- │ B+ │    │     │    │ LC │ RC │     │     │
╰────┴────┴────┴────┴────╯     ╰────┴────┴────┴─────┴─────╯
```

`BT`: bootloader (flash) mode `Vo`: mute `V-`/`V+`: volume down/up
`B-`/`B+`: brightness down/up `←↓↑→` (home row): mouse move
`LC`/`RC`: left/right mouse click `F1` and `F12` sit one row in (the outer
column that held them is gone).
