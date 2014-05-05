## Filing a Bug Report
1. **Check that you're up-to-date** with our [latest versions][latest-versions].  Your distro may
   be outdated.  It might be fixed in the latest version, and it's easy to [compile][compile-guide]
   and see.
2. **Tell us your distro!**  They might patch our stuff, so we'll have to check that.
3. *(optional, but appreciated)* **Tell us your versions of our dependencies.**  Your package
   manager probably has a means of doing this.
4. **Tell us how to reproduce the issue.**  Describe what you did to find the bug, so that we can
   get back there.  We can't get there without a roadmap, and you're the only one who's been there!
5. **Tell us what you think it should do.**  Tell us what you think is the expected behavior here.
   If it turns out that it wasn't a bug, we might reassign it as a Usability Report (see below).

[latest-versions]: http://undesktop.github.io/wiki/latest-versions.md
[compile-guide]: https://github.com/undesktop/libopkeychain/blob/master/build/README.md

## Filing a Feature Request
1. **Tell us what you want, what you really really want.**  If you wanna be my lover, you gotta get
   with my friends.  Make it last forever, friendship never ends.

## Filing a Usability Request/Report
1. **Tell us what it did.**  We need some context for your comments.
2. **Tell us what it ought to do.**  We'd love to hear what you think it ought to do.  We want to
   make a great product, and if you're unsatisfied, so are we.

## Filing a Pull Request
1. **Fork the repo and create a throwaway branch.**  We advise that you don't ever work directly on
   a long-term branch, just as a general rule.
2. If it's a bug, we encourage you to **write a regression test.**
3. **Fix the bug**, [make the tests (if any) pass][running-tests], and double-check your [style
   ][style-guide].
4. **Send a pull request.**
5. TravisCI will confirm that all the tests pass, and if everything is proper, **we'll merge!**

[running-tests]: http://undesktop.github.io/wiki/TODO.html
[style-guide]: http://undesktop.github.io/wiki/style-guide.html
