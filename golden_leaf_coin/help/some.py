


s = """
        src/front/application/cli/GLCCLIApplication.cpp
        src/front/application/cli/GLCCLIApplication.h
        src/front/application/mainarguments/GLCApplicationMainArgumentsParser.cpp
        src/front/application/mainarguments/GLCApplicationMainArgumentsParser.h
        src/glcstl/GLCDateTime.cpp
        src/glcstl/GLCDateTime.h
        src/glcstl/GLCDateTimeFormat.cpp
        src/glcstl/GLCDateTimeFormat.h
        src/glcstl/GLCDateTimeFormatTypes.cpp
        src/glcstl/GLCDateTimeFormatTypes.h
        src/glcstl/GLCBadInitializationException.cpp
        src/glcstl/GLCBadInitializationException.h
        src/glcstl/GLCException.cpp
        src/glcstl/GLCException.h
        src/glcstl/GLCFormatException.cpp
        src/glcstl/GLCFormatException.h
        src/glcstl/GLCInternalException.cpp
        src/glcstl/GLCInternalException.h
        src/front/application/gui/GLCGUIApplication.cpp
        src/front/application/gui/GLCGUIApplication.h
        src/front/application/GLCApplication.h
        src/front/application/GLCApplicable.h
        src/GLCVariables.h
        src/GLCVariables.cpp
        src/front/application/cli/GLCCLIDecoration.h
        src/front/application/cli/GLCCLIVariables.cpp
        src/front/application/cli/GLCCLIVariables.h
        src/front/application/cli/GLCCLIDecoration.cpp
        src/front/application/cli/GLCInput.cpp
        src/front/application/cli/GLCInput.h
        src/front/application/cli/GLCCLICommands.cpp
        src/front/application/cli/GLCCLICommands.h
        src/front/application/mainarguments/GLCApplicationProgramArguments.cpp
        src/front/application/mainarguments/GLCApplicationProgramArguments.h
        src/network/peer_to_peer/GLCNetworkPeerToPeerConfigurator.cpp
        src/network/peer_to_peer/GLCNetworkPeerToPeerConfigurator.h
        src/network/peer_to_peer/GLCNetworkPeerToPeerConstants.cpp
        src/network/peer_to_peer/GLCNetworkPeerToPeerConstants.h
        src/mine/configurator/GLCUserAction.cpp
        src/mine/configurator/GLCUserAction.h
        src/mine/csd/GLCCSD.cpp
        src/mine/csd/GLCCSD.h
        src/front/application/cli/tools/GLCCLICommandsHelper.cpp
        src/front/application/cli/tools/GLCCLICommandsHelper.h
        src/front/application/cli/tools/GLCCLICommandsHelper.h
        src/front/application/GLCApplicationConfiguration.cpp
        src/front/application/GLCApplicationConfiguration.h
        src/front/application/authentication/cli/GLCCLIAuthentification.cpp
        src/front/application/authentication/cli/GLCCLIAuthentification.h
        src/front/application/cli/GLCCLIInpput.cpp
        src/front/application/cli/GLCCLIInpput.h
""".split("\n")

s.sort()
for i in s:
    print(i)