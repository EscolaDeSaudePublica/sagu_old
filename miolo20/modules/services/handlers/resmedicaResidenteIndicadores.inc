<?php

$action = MIOLO::getCurrentAction();
$module = SAGU::getFileModule(__FILE__);

$mioloUserName = trim($MIOLO->getLogin()->id);
$busPerson = new BusinessBasicBusPerson();
$personData = $busPerson->getPersonByMioloUserName($mioloUserName);

$oferta = new MedOfertaDeUnidadeTematica( MIOLO::_REQUEST('ofertaDeUnidadeTematicaId') );

//Verifica se a pessoa logada � respons�vel no n�cleo e enfase da oferecida, caso sim, permite o acesso a tela de avalia��es  de indicadores
$verificaResponsavel = MedPreceptoria::responsavelNucleoEnfaseDaOferecida($personData->personId, $oferta->ofertaDeUnidadeTematicaId);

//Verifica permissao
if ( $personData->personId != $oferta->personId && $verificaResponsavel == DB_FALSE )
{
    $MIOLO->error(_M('Somente o preceptor desta unidade tem�tica pode acessar este conte�do.', $module));
}

SAGU::handle('resmedica', $action, _M('Residentes indicadores', $module), 'FrmResidenteIndicadores', 'FrmResidenteIndicadores', array('checkAccess' => false));
?>