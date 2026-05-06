<?php
date_default_timezone_set("Pacific/Noumea");

if (isset($_POST['valeur'])) {

    $valeur = $_POST['valeur'];

    file_put_contents("valeur.txt", $valeur);

    $date = date("Y-m-d");
    $heure = date("H:i:s");

    $fichier = fopen("valeur.csv", "a");
    fputcsv($fichier, [$date, $heure, $valeur]);
    fclose($fichier);

    echo "OK";
}
?>
