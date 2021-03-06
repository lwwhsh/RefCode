#           ( Type,   TaskName, DeviceName(createPhyChan),TriggerChannel, SigType, ClockChannel)
createDevice("NI6123", "Dev1_AI", "Dev1", "/Dev1/PFI0", "ai",  "/Dev1/PFI12")

#            ( TaskName, ChannelID, InputType, TagName, arg(MDS_Param or SCXI phyChannel))
createChannel("Dev1_AI",     "0",     "SXR",  "SXR049",     "Dev1/ai0")
createChannel("Dev1_AI",     "1",     "SXR",  "SXR050",     "Dev1/ai1")
createChannel("Dev1_AI",     "2",     "SXR",  "SXR051",     "Dev1/ai2")
createChannel("Dev1_AI",     "3",     "SXR",  "SXR052",     "Dev1/ai3")
createChannel("Dev1_AI",     "4",     "SXR",  "SXR053",     "Dev1/ai4")
createChannel("Dev1_AI",     "5",     "SXR",  "SXR054",     "Dev1/ai5")
createChannel("Dev1_AI",     "6",     "SXR",  "SXR055",     "Dev1/ai6")
createChannel("Dev1_AI",     "7",     "SXR",  "SXR056",     "Dev1/ai7")
