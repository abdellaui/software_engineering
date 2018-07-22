# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.MAIN.Debug:
/Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/main/Debug/MAIN:
	/bin/rm -f /Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/main/Debug/MAIN


PostBuild.TEST.Debug:
/Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/test/Debug/TEST:
	/bin/rm -f /Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/test/Debug/TEST


PostBuild.MAIN.Release:
/Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/main/Release/MAIN:
	/bin/rm -f /Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/main/Release/MAIN


PostBuild.TEST.Release:
/Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/test/Release/TEST:
	/bin/rm -f /Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/test/Release/TEST


PostBuild.MAIN.MinSizeRel:
/Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/main/MinSizeRel/MAIN:
	/bin/rm -f /Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/main/MinSizeRel/MAIN


PostBuild.TEST.MinSizeRel:
/Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/test/MinSizeRel/TEST:
	/bin/rm -f /Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/test/MinSizeRel/TEST


PostBuild.MAIN.RelWithDebInfo:
/Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/main/RelWithDebInfo/MAIN:
	/bin/rm -f /Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/main/RelWithDebInfo/MAIN


PostBuild.TEST.RelWithDebInfo:
/Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/test/RelWithDebInfo/TEST:
	/bin/rm -f /Users/abdullah/Desktop/Softwar\ Engineering\ Projekt\ 2\ 2/code/xcode/test/RelWithDebInfo/TEST




# For each target create a dummy ruleso the target does not have to exist
