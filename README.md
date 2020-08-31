# Lamport Scheme Crypto Back-end
Implements tiny set of operations with Lamport Signatures. <br/>
At the moment uses file-based interface for the communication (would be improved in next releases). <br/>


### Generate keys pair
```bash
> lamportc generate key

> ls
key.pkey  key.pubkey  lamportc 
```

* `generate` — command, sets the execution mode to keys generations. 
* `key` — the name for the keys pair (could be any, except empty).

Generated keys (public and private) would be written as `<key>.pkey` for private key 
and `<key>.pubkey` for public key into the same directory from where `lamportc` is launched.

<br/>

### Sign hash
```bash
> lamportc sign hash.bin key.pkey signature

> ls
hash.bin  key.pkey  key.pubkey  lamportc  signature.sig 
```

* `hash.bin` — the name of the file that contain 32-bytes binary interpretation of the hash. 
Must be accessible from the same directory from which the `lamportc` is launched. <br/>
* `key.pkey` — the name of the file that contains private key. <br/>
* `signature` — the name of the file that would contains generated signature. <br/>

`signature.sig` contains generated signature. <br/>

<br/>

### Verify signature

```bash
> lamportc verify hash.bin signature.sig key.pubkey
```

Returns `0 (success)` if signature corresponds to the pubkey, otherwise - returns `-1`.

* `hash.bin` — the name of the file that contain 32-bytes binary interpretation of the hash. 
Must be accessible from the same directory from which the `lamportc` is launched. <br/>
* `signature.sig` — the name of the file that contains signature to be checked. <br/>
* `key.pkey` — the name of the file that contains public key. <br/>
