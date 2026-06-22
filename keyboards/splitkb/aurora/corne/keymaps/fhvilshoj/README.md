
## Maps

This keymap is mid-transition to a 34-key Koepckeae model (see
`charlieflex-transition-plan.md`). **The outer pinky column is disabled
(`XXXXXXX`) on every layer**, so the board is logically **5 columns per hand**.
The diagrams below show only live keys. Thumbs are now **4** (2L/2R) — the
**outer** thumb of each side is disabled (Step 4 done), keeping the two closest
thumbs per hand. This is the target mental model; only the Koepckeae's
splay/thumb geometry is left to feel.

Home-row mods are **symmetric** — same finger sends the same mod on both hands:
pinky = ⌘ Cmd, ring = ⌥ Opt, middle = ⇧ Shift, index = ⌃ Ctrl.

### COMBOS

| Combo | Output | Notes |
|-------|--------|-------|
| `j`+`k` | `ESC` | |
| `s`+`d` | `⇥` TAB | home-row, base layer |
| `l`+`;` | `'` quote | base layer |
| `j`+`l` | `⌫` Backspace | tap = delete; **hold = repeat** (OS typematic) |
| `q`+`w` | `⇪` Caps Word | auto-cancels at end of word; keeps `_`/digits |
| `l`+`;` | `_` underscore | **CH layer only** |
| `.`+`/` | `` ` `` backtick | **CH layer only** |

### THUMBS (base layer)

| Thumb | Tap | Hold |
|-------|-----|------|
| left outer | *(disabled)* | *(disabled)* |
| left mid | — | `CH` symbol layer |
| left inner | `⏎` Enter | 🌐 Globe (`RALT`) |
| right inner | `␣` Space | `NUM` number/arrow layer |
| right mid | `⌥` Alt | ✦ Hyper (Ctrl+Alt+Shift+Gui) |
| right outer | *(disabled)* | *(disabled)* |

Hold **CH + NUM together** → `FN` layer (tri-layer). Backspace is the `j`+`l`
combo (tap = delete, hold = repeat); it left the thumbs entirely in Step 4.

🌐 Globe: macOS remaps Right-Alt → 🌐 in *Keyboard → Modifier Keys*, so the
firmware just sends `RALT`. Window tiling = 🌐(left-inner thumb) + Ctrl(`f`, also
a mod on NUM) + NUM(right-inner thumb) + arrow.

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
   │  ··  │  CH  │ 🌐⏎  │   │ ␣NUM │ ⌥Hyp │  ··  │
   ╰──────┴──────┴──────╯   ╰──────┴──────┴──────╯
```

`··` = disabled outer thumb. Tap/hold: CH=hold · 🌐⏎=Enter tap/Globe hold ‖
␣NUM=Space tap/NUM hold · ⌥Hyp=Alt tap/Hyper hold.

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
   │  ··  │  CH  │ 🌐⏎  │   │(NUM) │ ⌥Hyp │  ··  │
   ╰──────┴──────┴──────╯   ╰──────┴──────┴──────╯
```

Left home row keeps the GASC mods (so Ctrl on `f` is available for 🌐+Ctrl+arrow
window tiling). `FN` layer = hold CH + NUM together (tri-layer).

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
   │  ··  │ (CH) │ 🌐⏎  │   │ ␣NUM │ ⌥Hyp │  ··  │
   ╰──────┴──────┴──────╯   ╰──────┴──────┴──────╯
```

`_` and `` ` `` live on this layer's combos (`l;` and `./`) — they used to sit on
the now-removed outer column.

### FUNCTION KEYS AND MOUSE (FN)

Reached by holding CH + NUM together (tri-layer).

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
