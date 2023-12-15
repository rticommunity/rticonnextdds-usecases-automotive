# Build Helpers

Helpers for various build systems

- [cmake](cmake/README.md)

---

NOTE
- This `build-helpers` directory could be a standalone `git submodule`
- Since the `databus` project is required by all the components, keeping the
  `build-helpers` here as a sub-directory of the `databus` project eliminates
  the need to manage an extra dependency, and simplifies the packaging
