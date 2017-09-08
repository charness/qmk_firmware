TAP_DANCE_ENABLE = yes
UNICODE_ENABLE = yes
#UCIS_ENABLE = yes
#UNICODEMAP_ENABLE = yes
SLEEP_LED_ENABLE = yes  # Breathing sleep LED during USB suspend
COMMAND_ENABLE   = no  # Commands for debug and configuration
RGBLIGHT_ENABLE = yes
MIDI_ENABLE = no

# ifndef QUANTUM_DIR
# 	include ../../../../Makefile
# endif

IMAGE:=ergodox_ez_grafov.hex
PRJROOT :=$(realpath $(shell echo `pwd`/../../../..))

buildez:
	cd ${PRJROOT}
	docker run -e keymap=grafov -e keyboard=ergodox_ez -e subproject=defaultsp --rm -v ${PRJROOT}:/qmk:rw edasque/qmk_firmware

flash: ${PRJROOT}/.build/${IMAGE}
	@cp ${PRJROOT}/.build/${IMAGE} ~
	~/bin/teensy ~/${IMAGE}
	@rm -f ~/${IMAGE}

init:
	~/bin/ez.sh
#	~/bin/qwerty.sh
	xset r rate 300 90


