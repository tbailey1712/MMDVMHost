This is a fork of https://github.com/jpronans/MMDVMHost
Which is a fork of https://github.com/g4klx/MMDVMHost that adds GPS decoding to TYT/Retevis radios

Goals:
1. Create an APRS module from YSFGateway (https://github.com/g4klx/YSFClients/tree/master/YSFGateway) specifically for sending GPS data to an APRS server
2. Merge the module into the MMDVMHost codebase and call it from DMRSlot
3. Customize the Nextion display to include TG and GPS data for received stations
