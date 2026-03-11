{
  description = "Tornium OC scenario graphs";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      supportedSystems = [ "x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin" ];
      forAllSystems = f: nixpkgs.lib.genAttrs supportedSystems (system: f system);
    in
    {
      packages = forAllSystems (system:
        let
          pkgs = import nixpkgs { inherit system; };
          pythonPkg = pkgs.callPackage ./package.nix { };
        in
        {
          tornium_oc_graph = pythonPkg;
          default = pythonPkg;
        });

      overlays.default = final: prev: {
        python313Packages = prev.python313Packages.overrideScope (pyFinal: pyPrev: {
          tornium_oc_graph = final.callPackage ./package.nix {
            src = self;
          };
        });
      };

      devShells = forAllSystems (system:
        let
          pkgs = import nixpkgs { inherit system; };
        in
        {
          default = pkgs.mkShell {
            packages = [
              (pkgs.python3.withPackages (ps: [
                self.packages.${system}.tornium_oc_graph
              ]))
            ];
          };
        });
    };
}
