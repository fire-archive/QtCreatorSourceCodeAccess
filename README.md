QtCreatorSourceCodeAccess
==============================

This project is under the MIT license. By submitting a patch to the project you agree to assign it the same MIT license as the project. See `LICENSE.txt`.

### Instructions

Clone this to your UnrealEngine directory at `Engine/Plugins/Developer`.

Compile the plugin. May require a full recompile of the editor. (Restart editor)

Enable this as your code view editor.

Add to Engine/Config/Linux/LinuxEngine.ini

[/Script/SourceCodeAccess.SourceCodeAccessSettings]
PreferredAccessor=QtCreatorSourceCodeAccessor

Tested to work on Unreal Engine 4.17.1

### Donations

Accepting funding at: https://www.patreon.com/ernestlee
