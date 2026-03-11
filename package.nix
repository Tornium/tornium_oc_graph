{ lib, python3Packages, pkgs, src, ...}:

python3Packages.buildPythonPackage {
  pname = "tornium_oc_graph";
  version = "0.1.2-dev";
  pyproject = true;

  src = builtins.path{ path = src; };

  buildInputs = [ python3Packages.scikit-build-core ];
  nativeBuildInputs = [
    python3Packages.scikit-build-core
    pkgs.cmake
    pkgs.ninja
  ];

  build-system = with python3Packages; [ scikit-build-core ];
  preConfigure = ''
    mkdir c_src/build/
    echo $(pwd)
    ls -R .
  '';
  cmakeDir = "../c_src/build";

  propagatedBuildInputs = [];
  pythonImportCheck = [ "tornium_oc_graph" ];

  meta = with lib; {
    description = "Tornium OC scenario graphs";
    license = licenses.asl20;
  };
}
