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
 * Redireciona para tela de encontros do Resmedica
 *
 * @author Lu�s Felipe Wermann [luis_felipe@solis.com.br]
 *
 * @version $Id$
 *
 * \b Maintainers: \n
 * Lu�s Felipe Wermann [luis_felipe@solis.com.br]
 *
 * @since
 * Class created on 24/11/2014
 */

$action = MIOLO::getCurrentAction();
$module = SAGU::getFileModule(__FILE__);

$mioloUserName = trim($MIOLO->getLogin()->id);
$busPerson = new BusinessBasicBusPerson();
$personData = $busPerson->getPersonByMioloUserName($mioloUserName);

$oferta = new MedOfertaDeUnidadeTematica( MIOLO::_REQUEST('ofertaDeUnidadeTematicaId') );

//Verifica se a pessoa logada � respons�vel no n�cleo e enfase da oferecida, caso sim, permite o acesso a tela de encontros
$verificaResponsavel = MedPreceptoria::responsavelNucleoEnfaseDaOferecida($personData->personId, $oferta->ofertaDeUnidadeTematicaId);

$preceptores = $oferta->preceptores;

$preceptoresArray = array();
foreach ($preceptores as $preceptor) {
    $preceptorObj = new MedPreceptoria($preceptor->preceptorId);
    $preceptoresArray[] = $preceptorObj->personId;
}

//Verifica permissao
if ( !in_array($personData->personId, $preceptoresArray) || $verificaResponsavel == DB_FALSE )
{
    $MIOLO->error(_M('Somente o preceptor desta unidade tem�tica pode acessar este conte�do.', $module));
}

SAGU::handle('resmedica', $action, _M('Digita��o de faltas', $module), 'FrmFaltasDaOfertaDaUnidadeTematica', 'FrmFaltasDaOfertaDaUnidadeTematica', array('checkAccess' => false));
?>