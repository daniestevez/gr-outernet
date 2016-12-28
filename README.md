# gr-outernet
GNUradio OOT module for Outernet

This repository contains a GNUradio decoder for [Outernet](http://outernet.is/)

The decoder receives the Outernet frames from the L-band signal. You can use
[free-outernet](https://github.com/daniestevez/free-outernet/) to recover files
from the frames.

The most useful GRC flowgraph is `examples/outernet-rtlsdr.grc`. This flowgraph
receives the Outernet L-band signal and saves the frame to a KISS file in
`/tmp/outernet.kiss`. It also sends the frames by UDP. This will be used in a
future version of free-outernet to do realtime file reception (for now it only
works with the KISS file).

The flowgraph is preset for the I-4 F3 signal that is used in the Americas. If
you are on another area, please change the variables `freq` and `centre_freq` in
the flowgraph accordingly.

The flowgraph should start receiving frames automatically. The hex dump of the
received frames will be printed in the console. In principle, there is no need
for adjustment, but perhaps it is necesary to adjust the fine tuning frequency
in the receiver GUI, since the crystal of the RTL-SDR may be a bit off (even if
it is a good 0.5ppm TCXO).

The rest of the parameters are already adjusted for good results, but you can
try to play with them to improve performance. You can monitor the signal quality
by looking at the constellation plot in the BPSK tab. You aim for all the blue dots
clustered around the points -1 and 1 (which represent the two symbols of the
BPSK signal), with few points near 0 (which means ambiguities due to noise that
will possibly result in bit errors). If you get improved results with some
combination of parameters other than the stock one, please let me know.

The flowgraph needs [gr-kiss](https://github.com/daniestevez/gr-kiss/).

## Sample IQ recording

For testing, you can use a [sample IQ recording by Scott K4KDR](https://drive.google.com/open?id=0B2pPGQkeEAfdRjV0a1IyNTBIalk).
You should open it with the flowgraph `examples/outernet-recording-example.grc`