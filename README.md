Hootchain Core staging tree
===========================

https:/hootchain.org

For an immediately usable, binary version of the Hootchain Core software, see releases in our GitHub.

Further information about Hootchain Core is available in the [doc folder](/doc).

What is HootChain?
-------------

Hootchain is on a mission transform decenterlized finance as most of the people know about it today. We believe that everyone, not just a select few, should have access to a truly decentralized blockchain. Our platform breaks down barriers by making participation accessible for all. But that doesn't mean anonymity reigns supreme. This balance ensures user privacy while preventing the blockchain from becoming a haven for illegal activities. We believe this fosters trust – a cornerstone for widespread cryptocurrency adoption.

Imagine an ecosystem that empowers everyone to participate in the future of finance using our platform. That's the future HootChain is building. We're innovating DeFi to make it more approachable and trustworthy, paving the way for a more inclusive and secure financial landscape.


For more information read the original HootChain whitepaper.

License
-------

Hootchain Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is meant to be stable. Development is normally done in separate branches.
[Tags](https://github.com/hootchain/tags) are created to indicate new official,
stable release versions of Hootchain Core.

The `develop` branch is regularly built (see doc/build-*.md for instructions) and tested, but is not guaranteed to be
completely stable.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md)
and useful hints for developers can be found in [doc/developer-notes.md](doc/developer-notes.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`

The Travis CI system makes sure that every pull request is built for Windows, Linux, and macOS, and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.
