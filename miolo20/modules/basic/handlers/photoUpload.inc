<?php
/**
 * <--- Copyright 2005-2010 de Solis - Cooperativa de Solu��es Livres Ltda.
 *
 * Este arquivo � parte do programa Sagu.
 *
 * O Sagu � um software livre; voc� pode redistribu�-lo e/ou modific�-lo
 * dentro dos termos da Licen�a P�blica Geral GNU como publicada pela Funda��o
 * do Software Livre (FSF); na vers�o 2 da Licen�a.
 *
 * Este programa � distribu�do na esperan�a que possa ser �til, mas SEM
 * NENHUMA GARANTIA; sem uma garantia impl�cita de ADEQUA��O a qualquer MERCADO
 * ou APLICA��O EM PARTICULAR. Veja a Licen�a P�blica Geral GNU/GPL em
 * portugu�s para maiores detalhes.
 *
 * Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral GNU, sob o t�tulo
 * "LICENCA.txt", junto com este programa, se n�o, acesse o Portal do Software
 * P�blico Brasileiro no endere�o www.softwarepublico.gov.br ou escreva para a
 * Funda��o do Software Livre (FSF) Inc., 51 Franklin St, Fifth Floor, Boston,
 * MA 02110-1301, USA --->
 *
 * Obtem o download de arquivo pedido para o usuario
 *
 * @author Moises Heberle [moises@solis.coop.br]
 *
 * @version $Id$
 *
 * \b Maintainers: \n
 * Moises Heberle [moises@solis.coop.br]
 * Arthur Lehdermann [arthur@solis.coop.br]
 *
 * @since
 * Class created on 25/04/2011
 */

unset($_SESSION["SPhotoManager"]["photoInfo"]);
$uploadInfo = array();
$path = SPhotoManager::getTmpFolder();
$allowedExt = array('jpg', 'jpeg', 'png', 'gif');

if (!is_dir($path)) {
    mkdir($path, 0777, true);

}

foreach($_FILES as $field => $file)
{
    if (!($file["error"] > 0))
    {
        $operatorId = $_POST["operatorId"];

        $explode = explode(".", $file["name"]);

        $fileExt = $explode[sizeof($explode) - 1];

        $fileName = 'photo_' . $operatorId . '.';

        // Limpa a pasta tempor�ria por arquivos n�o salvos pelo operador.
        foreach($allowedExt as $ext)
        {
            if(file_exists($path . $fileName . $ext))
            {
                unlink($path . $fileName . $ext);

            }

        }

        $fileName = $fileName . $fileExt;

        if((in_array($fileExt, $allowedExt)) && (move_uploaded_file($file["tmp_name"], $path . $fileName)))
        {
            $uploadInfo = new stdClass();

            $uploadInfo->tmpName = $fileName;
            $uploadInfo->ext = $fileExt;
            $uploadInfo->type = $file["type"];

            $_SESSION["SPhotoManager"]["photoInfo"] = $uploadInfo;
                        
        }

    }

}