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
 * @author Moises Heberle [moises@solis.coop.br]
 *
 * @version $Id$
 *
 * \b Maintainers: \n
 * Moises Heberle [moises@solis.coop.br]
 * Samuel Koch [samuel@solis.coop.br]
 *
 * @since
 * Class created on 07/02/2011
 *
 **/

$module = SAGU::getFileModule(__FILE__);
$function = MIOLO::_REQUEST('function');

$i=1;
if ( ($function != 'update') )
{
    $steps[$i++] = new SStepInfo('FrmFinalExaminationCurricularComponent', _M('Sele��o de disciplina', $module), $module);
}
$steps[$i++] = new SStepInfo('FrmFinalExaminationTheme', _M('Tema', $module), $module);
$steps[$i++] = new SStepInfo('FrmFinalExaminationDirectors', _M('Orientadores', $module), $module);
$steps[$i++] = new SStepInfo('FrmFinalExaminationExaminingBoard', _M('Banca examinadora', $module), $module);
$steps[$i++] = new SStepInfo('FrmFinalExaminationNotes', _M('Notas', $module), $module);

SAGU::handle($module, $action, _M('Detalhamento do TCC', $module), 'FrmFinalExaminationSearch', $steps, 'FrmFinalExamination');
?>