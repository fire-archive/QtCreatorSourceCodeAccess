QtCreatorSourceCodeAccess
==============================

This project is under the MIT license. By submitting a patch to the project you agree to assign it the same MIT license as the project. See `LICENSE.txt`.

### Instructions

Clone this to your UnrealEngine directory at `Engine/Plugins/Developer`.

Enable this as your code view editor.

Add to Engine/Config/Linux/LinuxEngine.ini

[/Script/SourceCodeAccess.SourceCodeAccessSettings]
PreferredAccessor=QtCreatorSourceCodeAccessor

Reported to work for Unreal Engine 4.7.

```
cd /usr/bin/
sudo ln -s clang-3.5 clang
```

### Donations

Accepting donations at: https://www.patreon.com/ernestlee
