# flox-connectors — archived

This repository has been merged into the main [FLOX](https://github.com/FLOX-Foundation/flox) repository as of v0.6.0. The native exchange connectors (Bybit, Bitget, Hyperliquid, Polymarket) now live under [`connectors/`](https://github.com/FLOX-Foundation/flox/tree/main/connectors) in the FLOX repo and build with:

```bash
cmake -B build -DFLOX_BUILD_CONNECTORS=ON
```

See the [connectors README](https://github.com/FLOX-Foundation/flox/blob/main/connectors/README.md) for adapter notes and the optional Polymarket Rust toolchain step.

This repo is archived (read-only). Open issues were transferred to the [FLOX issue tracker](https://github.com/FLOX-Foundation/flox/issues); please file new ones there.
