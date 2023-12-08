{
  description = "Rellikeht's build of suckless dmenu";

  inputs.nixpkgs.url = github:NixOS/nixpkgs;

  outputs = {
    self,
    nixpkgs,
  }: let
    system = "x86_64-linux";
  in {
    packages.x86_64-linux.default = with import nixpkgs {system = system;};
      stdenv.mkDerivation {
        name = "dmenu";
        src = self;

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
  };
}
