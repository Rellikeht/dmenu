{
  description = "Rellikeht's build of suckless dmenu";

  inputs = {
    nixpkgs.url = github:NixOS/nixpkgs;
    flake-utils.url = github:numtide/flake-utils;
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachSystem [
      "x86_64-linux"
      "i686-linux"
      "aarch64-linux"
      "armv7l-linux"
    ] (system: let
      pkgs = nixpkgs.legacyPackages.${system};
      name = "dmenu";
      src = self;
    in {
      packages.default = pkgs.stdenv.mkDerivation rec {
        inherit name system src;

        PREFIX = "$(out)";
        CC = pkgs.gcc;

        buildInputs = with pkgs; [
          xorg.libX11
          xorg.libXft
          xorg.libXinerama
        ];

        buildPhase = "
            make clean
            make
            ";

        installPhase = "
          mkdir -p $out/bin
          make install
          ";
      };
    });
}
