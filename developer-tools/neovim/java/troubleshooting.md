# Troubleshooting Java Setup for Neovim

## Problems
- Problem
    - LSP is not working because the lombok library cannot be found by jdtls.
    - Solution
      - Download lombok.jar directly.
      - Store jar file to '$HOME/.local/share/java/lombok.jar.
      - Add this export line: `export JDTLS_JVM_ARGS="-javaagent:$HOME/.local/share/java/lombok.jar")` to the shell configuration file.
