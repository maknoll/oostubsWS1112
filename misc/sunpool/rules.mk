${EMUTARGET}: ${TARGET}
	@mkisofs -quiet -graft-points -R -b boot/grub/stage2_eltorito -input-charset ascii -A "OOStubs Boot CD" -no-emul-boot -boot-load-size 4 -boot-info-table -o ${BIN}/oostubs.iso ./boot/grub/stage2_eltorito=misc/sunpool/stage2_eltorito ./ boot/grub/menu.lst=misc/sunpool/grub.conf ./oostubs=bin/oostubs
