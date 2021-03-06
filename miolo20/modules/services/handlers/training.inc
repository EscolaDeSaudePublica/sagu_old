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
 * Pupil services handler.
 * Used to access the training services
 *
 * @author Fabiano Tomasini [fabiano@solis.coop.br]
 *
 * @version $Id$
 *
 * \b Maintainers: \n
 * Arthur Lehdermann [arthur@solis.coop.br]
 * Fabiano Tomasini [fabiano@solis.coop.br]
 *
 * @since
 * Class created on 13/04/2011
 */

$home = 'main:training';
$module = SAGU::getFileModule(__FILE__);
$navbar->addOption(_M('Servi�os de est�gio', $module), $module, $home, null, array('function' => 'resetStack'));

if ( !$MIOLO->invokeHandler($module, 'training/' . $context->shiftAction()) )
{
    $btnClose = $MIOLO->getActionURL('sagu2', 'main');
    $mioloUserName = trim($MIOLO->getLogin()->id);

    $pnlPupil = new MActionPanel('pnlTraining', _M('Servi�os de est�gio', $module), NULL, $btnClose, $MIOLO->getUI()->getImage($module, 'training-16x16.png'));
    $pnlPupil->setControlSize('100px', '70px');

    unset($menuItem);
    $menuItem = array();
    $menuItem[] = array(_M('Hist�rico de est�gios', $module), 'training-32x32.png', "$home:trainingHistory");
    //$menuItem[] = array(_M('Localiza��o de est�gio', $module), 'training-32x32.png', "$home:trainingLocation");
    
    if( $MIOLO->checkAccess('FrmDocumentRequest', A_ACCESS, false, true) )
    {
        $menuItem[] = array(_M('Solicita��o de servi�o', $module), 'documentRequest-32x32.png', "main:documentRequest");
    }
    
    if( $MIOLO->checkAccess('FrmPersonalAgenda', A_ACCESS, false, true) )
    {
        $menuItem[] = array(_M('Agenda pessoal', $module), 'personalAgenda-32x32.png', "main:personalAgenda");
    }
        
    $sortMenuItem = SAGU::arraySort($menuItem, 0);
    foreach ( $sortMenuItem as $m )
    {
        $pnlPupil->addAction($m[0], $MIOLO->getUI()->getImage($module, $m[1]), $module, $m[2], $m[3], $m[4]);
    }
    $theme->appendContent($pnlPupil);
    $sep = new MSeparator();
    $theme->appendContent($sep);
}
?>