setws ./proj
cd ./proj
app create -name zb_ps_blink_leds -hw ../../hw/proj/zb_ps_blink_leds_wrapper.xsa -os standalone -proc ps7_cortexa9_0 -template {Empty Application}
importsources -name zb_ps_blink_leds -path ../src/
app build -name zb_ps_blink_leds