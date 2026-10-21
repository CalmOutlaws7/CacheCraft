# Security Policy

## Project Status

CacheCraft is an educational C++20 in-memory key-value storage engine.
It is under active development and is not intended for production use.

## Security Principles

- Validate client input and handle malformed requests safely.
- Apply explicit limits to request sizes and resource consumption.
- Bind network services to localhost by default.
- Avoid exposing unauthenticated services to untrusted networks.
- Never commit passwords, access tokens, private keys, or other secrets.
- Test error handling, boundary conditions, and malformed input.
- Keep dependencies and build tools reasonably up to date.

These are development goals, not a claim that every safeguard is
already implemented.

## Reporting a Vulnerability

Please report security issues privately through GitHub's security
advisory reporting feature when available, rather than publishing
details of an exploitable issue before it can be addressed.

## Disclaimer

CacheCraft is a learning project. It has not been independently
audited and must not be assumed secure for production workloads.
